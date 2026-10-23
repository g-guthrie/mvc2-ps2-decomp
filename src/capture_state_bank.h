#ifndef MVC2_CAPTURE_STATE_BANK_H
#define MVC2_CAPTURE_STATE_BANK_H
typedef void (*CaptureEntryCallback)(unsigned char *);
typedef void (*CaptureContextCallback)(unsigned char *, unsigned char *);
/* The native context alias begins sixteen bytes into this 44-byte owner. */
typedef struct {
    CaptureEntryCallback entry[4];
    CaptureContextCallback capture[7];
} CaptureStateBank;
typedef char CaptureStateBankSize[sizeof(CaptureStateBank) == 44 ? 1 : -1];
extern const CaptureStateBank jtbl_0045AD80;
#endif
