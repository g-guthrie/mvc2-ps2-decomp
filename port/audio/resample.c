#include "resample.h"
#include <math.h>
#include <string.h>

#define RS_CUTOFF 0.95f
#define RS_BETA 9.0

static float K[RS_HALF * RS_RES + 2];
static int k_ready;
float rs_poly[RS_PHASES + 1][RS_TAPS];

static double bessel_i0(double x)
{
    double s = 1, t = 1;
    for (int k = 1; k < 40; k++) {
        t *= (x / (2 * k)) * (x / (2 * k));
        s += t;
        if (t < 1e-12 * s) break;
    }
    return s;
}

void rs_init(void)
{
    if (k_ready) return;
    double i0b = bessel_i0(RS_BETA);
    for (int i = 0; i <= RS_HALF * RS_RES + 1; i++) {
        double x = (double)i / RS_RES;
        double r = x / RS_HALF;
        double win = r >= 1 ? 0 : bessel_i0(RS_BETA * sqrt(1 - r * r)) / i0b;
        double a = M_PI * RS_CUTOFF * x;
        double sinc = x == 0 ? 1 : sin(a) / a;
        K[i] = (float)(RS_CUTOFF * sinc * win);
    }
    k_ready = 1;
    for (int p = 0; p <= RS_PHASES; p++) {
        double frac = (double)p / RS_PHASES, sum = 0;
        for (int k = 0; k < RS_TAPS; k++) {
            rs_poly[p][k] = rs_kernel((float)((k - (RS_HALF - 1)) - frac));
            sum += rs_poly[p][k];
        }
        for (int k = 0; k < RS_TAPS; k++) rs_poly[p][k] = (float)(rs_poly[p][k] / sum);
    }
}

float rs_kernel(float x)
{
    float t = fabsf(x) * RS_RES;
    int i = (int)t;
    if (i >= RS_HALF * RS_RES) return 0;
    float f = t - (float)i;
    return K[i] + f * (K[i + 1] - K[i]);
}

int rs_weights(double frac, float scale, float *w, int *n)
{
    /* taps at input offsets k (relative to i0) with |k - frac| < RS_HALF*scale */
    float half = RS_HALF * scale;
    int first = (int)ceil(frac - half);
    int last = (int)floor(frac + half);
    if (last - first + 1 > RS_MAX_TAPS) last = first + RS_MAX_TAPS - 1;
    float sum = 0, inv = 1.0f / scale;
    int m = 0;
    for (int k = first; k <= last; k++) {
        float v = rs_kernel((float)((k - frac) * inv));
        w[m++] = v;
        sum += v;
    }
    if (sum != 0) {
        float g = 1.0f / sum;
        for (int k = 0; k < m; k++) w[k] *= g;
    }
    *n = m;
    return first;
}

void rs_stream_init(RsStream *s, double in_rate, double out_rate)
{
    rs_init();
    memset(s, 0, sizeof *s);
    s->step = in_rate / out_rate;
    s->passthrough = fabs(s->step - 1.0) < 1e-12;
    rs_stream_reset(s);
}

void rs_stream_reset(RsStream *s)
{
    /* RS_HALF*scale frames of leading silence act as history */
    memset(s->buf, 0, sizeof s->buf);
    int pre = RS_HALF * RS_MAX_STEP + 2;
    s->fill = pre;
    s->pos = pre;
}

static void refill(RsStream *s, RsPull pull, void *ctx, int need_upto)
{
    /* keep history before pos, drop the rest */
    int keep_from = (int)s->pos - (RS_HALF * RS_MAX_STEP + 2);
    if (keep_from > 0) {
        int n = s->fill - keep_from;
        memmove(s->buf[0], s->buf[0] + keep_from, n * sizeof(float));
        memmove(s->buf[1], s->buf[1] + keep_from, n * sizeof(float));
        s->fill = n;
        s->pos -= keep_from;
        need_upto -= keep_from;
    }
    float tmp[2 * 512];
    while (s->fill < need_upto && s->fill < RS_BUF) {
        int want = RS_BUF - s->fill;
        if (want > 512) want = 512;
        int got = pull ? pull(ctx, tmp, want) : 0;
        if (got <= 0) { /* starve: pad with silence */
            got = want;
            memset(tmp, 0, sizeof(float) * 2 * got);
        }
        for (int i = 0; i < got; i++) {
            s->buf[0][s->fill + i] = tmp[2 * i];
            s->buf[1][s->fill + i] = tmp[2 * i + 1];
        }
        s->fill += got;
    }
}

void rs_stream_run(RsStream *s, RsPull pull, void *ctx, float *out, int frames)
{
    if (s->passthrough) {
        int done = 0;
        while (done < frames) {
            int got = pull ? pull(ctx, out + 2 * done, frames - done) : 0;
            if (got <= 0) {
                memset(out + 2 * done, 0, sizeof(float) * 2 * (frames - done));
                break;
            }
            done += got;
        }
        return;
    }
    float scale = s->step > 1 ? (float)s->step : 1.0f;
    float w[RS_MAX_TAPS];
    for (int o = 0; o < frames; o++) {
        int i0 = (int)floor(s->pos);
        int span = (int)ceil(RS_HALF * scale) + 2;
        if (i0 + span >= s->fill) refill(s, pull, ctx, i0 + span + 1);
        i0 = (int)floor(s->pos);
        double frac = s->pos - i0;
        int n, first = rs_weights(frac, scale, w, &n);
        float l = 0, r = 0;
        for (int k = 0; k < n; k++) {
            int idx = i0 + first + k;
            if (idx < 0 || idx >= s->fill) continue;
            l += w[k] * s->buf[0][idx];
            r += w[k] * s->buf[1][idx];
        }
        out[2 * o] = l;
        out[2 * o + 1] = r;
        s->pos += s->step;
    }
}
