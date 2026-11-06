"""Bounded paired execution experiment. Never registers code or changes acceptance."""
import argparse, copy, hashlib, json, random, shutil, struct, subprocess, sys, tempfile, time
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from core import load, number, verify_rom, elf_segments, link_map, sha, verify_tools
from build import compile_unit
from behavioral_evidence import fingerprint, REVISION
BASE = 0x0c000000
HERE = Path(__file__).resolve().parent
UNITS = ['tu_0c1e6a68', 'tu_0c1e8358', 'tu_0c035160', 'ud2_04']

def cases_for(uid):
    cases=[]
    def add(name,entry,args,init,expect):
        cases.append(dict(name=name,entry='_func_'+entry,arguments=args,initializations=init,expectations=expect))
    def ret(n): return dict(kind='return',value=n & 0xffffffff)
    if uid=='tu_0c1e6a68':
        rng=random.Random(20261004)
        scenarios=[('disabled',0,[(18,1)]*8),('empty',1,[(0,0)]*8),('all_present',1,[(18,1)]*8),('all_type1',1,[(1,2)]*8),('all_invalid_type1',1,[(1,0xffff0000)]*8)]
        for i in range(8):
            slots=[(0,0)]*8;slots[i]=(18,0xffff0000);scenarios.append((f'blocking_slot_{i}',1,slots))
            slots=[(0,0)]*8;slots[i]=(1,3);scenarios.append((f'valid_slot_{i}',1,slots))
        for i in range(12):scenarios.append((f'mixed_{i}',1,[(rng.choice([0,1,17,18,19,-1]),rng.choice([0,1,0xffff0000,0xffffffff])) for _ in range(8)]))
        for name,enabled,slots in scenarios:
            init=[[32,0x2d6f84,0x700000],[8,0x700047,enabled]]
            for i,(typ,identity) in enumerate(slots):init += [[32,0x312834+i*60+4,typ],[32,0x312834+i*60+8,identity]]
            mask=sum(1<<i for i,(typ,identity) in enumerate(slots) if typ in (1,18) and identity!=0xffff0000)
            for entry in ['0c1e6a68','0c1e6af4']:
                expected=-1 if not enabled or (entry=='0c1e6a68' and (18,0xffff0000) in slots) else mask
                add(name+'_'+entry,entry,[],init,[ret(expected)])
    elif uid=='tu_0c1e8358':
        rng=random.Random(20261004)
        patterns=[('zero',[0]*80),('ones',[1]*80),('high',[255]*80),('signed_edge',[128,127]*40),('ramp',list(range(80))),('random',[rng.randrange(256) for _ in range(80)])]
        for name,data in patterns:
            for n in [0,1]:
                start=0x302e14+n*512;init=[[8,start+i,b] for i,b in enumerate(data)]+[[8,start+80,71]]
                add(name+f'_bank{n}','0c1e8358',[n],init,[ret(sum(data)&255)])
            start=0x2fc048;init=[[8,start+i,b] for i,b in enumerate(data)]+[[8,start+80,71]]
            add(name+'_short','0c1e8376',[],init,[ret(sum(data[:75])&255)])
    elif uid=='ud2_04':
        actor=0x700000
        for flag in [0,1]:
            for mode in [0,5]:
                for timer in [-1,0,1,2,3]:
                    init=[[8,0x2f8338,mode],[8,0x2f833b,flag],[8,actor+6,7],[8,actor+32,2],[32,actor+0x2c4,timer],[32,0x24e178+8,0x710000]]
                    def write(offset,value,size=8):return dict(kind='write',address=actor+offset,value=value,size=size)
                    ex=[write(0x3f8,2),write(0x328,5)]
                    if not flag and mode!=5:ex.append(write(0x2c4,timer-1,32))
                    if flag or mode==5 or timer-1<=0:
                        ex += [write(0x3f9,0),write(0x3f8,0),write(0x327,0),write(0x328,0),write(6,8),dict(kind='call',symbol='_func_0c02a0c4',arguments=[actor,22,11])]
                    else:ex.append(dict(kind='call',symbol='_func_pilot_callback',arguments=[actor]))
                    add(f'countdown_{flag}_{mode}_{timer}','0c12f9d4',[actor],init,ex)
    else:
        for values in [list(range(11)),[0xffffffff-i for i in range(11)],[0x80000000,0x7fffffff,0,1,2,3,4,5,6,7,8]]:
            init=[[32,0x2fb248+84+i*4,v] for i,v in enumerate(values)]
            ex=[dict(kind='call',symbol='_func_0c02c32e',arguments=[25,25-i,0,0x22dc78,values[i]],variadic_fixed=3) for i in range(10)]
            ex += [dict(kind='call',symbol='_func_0c0351cc',arguments=[])]
            add('display_'+str(len(cases)),'0c035160',[],init,ex)
    return cases


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--simulator',type=Path,required=True);ap.add_argument('--unit',choices=UNITS,action='append');ap.add_argument('--case', action='append', help='Exact case name; repeat to select several (requires --unit)');ap.add_argument('--php',default='php');ap.add_argument('--out',type=Path,default=ROOT/'build/simulator-pilot');args=ap.parse_args()
    if args.case and (not args.unit or len(args.unit) != 1):ap.error('--case requires exactly one --unit')
    args.out=args.out.resolve();args.out.mkdir(parents=True,exist_ok=True)
    verify_tools()
    pilot_hash=sha(Path(__file__).read_bytes());adapter_hash=sha((HERE/'run.php').read_bytes())
    simulator=args.simulator.resolve()
    revision=subprocess.check_output(['git','-C',str(simulator),'rev-parse','HEAD'],text=True).strip()
    if revision!='291be8e458ddc2ecad9c3fd27b4e48a8b17e73aa':raise ValueError('Use the reviewed v0.1.48 simulator revision')
    if subprocess.check_output(['git','-C',str(simulator),'status','--porcelain'],text=True).strip():raise ValueError('Simulator checkout must be clean')
    target=load(ROOT/'config/target.json');rom=verify_rom(target);off=number(target['main']['rom_offset']);main_image=rom[off:off+number(target['main']['size'])];main_base=number(target['main']['address'])
    units={u['id']:u for u in load(ROOT/'config/units.json')}
    results={};start=time.monotonic();all_valid=True
    for uid in (args.unit or UNITS):
        u=units[uid];selected_cases=cases_for(uid)
        if args.case:
            selected_cases=[case for case in selected_cases if case['name'] in args.case]
            if {case['name'] for case in selected_cases} != set(args.case):ap.error('unknown case name')
        inputs=fingerprint(u,selected_cases)
        assert len(u['sections'])==1 and u['sections'][0]['section']=='P'
        part=u['sections'][0];address=number(part['address']);length=part['size'];original=bytearray(main_image[address-main_base:address-main_base+length]);patches=[]
        allowed={number(a) for a in u.get('imports',{}).values()}|{number(a) for a in u['exports'].values()}
        for interior in part.get('interior',[]):
            lo=number(interior['address']);hi=lo+interior['size']
            for site in range((lo+3)&~3,hi-3,4):
                value=struct.unpack_from('<I',original,site-address)[0]
                if value in allowed:
                    struct.pack_into('<I',original,site-address,value-BASE);patches.append(dict(site=hex(site),original=hex(value),rebased=hex(value-BASE)))
                elif BASE<=value<BASE+0x1000000:raise ValueError(f'Unaccounted native pointer {value:x} in pool')
        # Every changed reference word is reversible; native instructions are untouched.
        restored=bytearray(original)
        for p in patches:struct.pack_into('<I',restored,int(p['site'],16)-address,int(p['original'],16))
        assert restored==main_image[address-main_base:address-main_base+length]
        source=(ROOT/u['source']).read_text()
        mutation={'tu_0c1e6a68':('if(!dat_0c2d6f84->b47)return -1;','if(dat_0c2d6f84->b47)return -1;'),'tu_0c1e8358':('limit=80','limit=79'),'tu_0c035160':('row-i','row+i'),'ud2_04':('0x2c4)) <= 0','0x2c4)) <= 2')}[uid]
        assert mutation[0] in source
        variants={};symbols={**{k:number(v)-BASE for k,v in u.get('imports',{}).items()},**{k:number(v)-BASE for k,v in u['exports'].items()}}
        image=bytearray(address-BASE+len(original));image[address-BASE:]=original
        variants['retail']=(bytes(image),symbols)
        with tempfile.TemporaryDirectory(dir=args.out,prefix='compile-') as td:
            work=Path(td);shutil.copytree(ROOT/'toolchain/hitachi-shc-5.0r31',work,dirs_exist_ok=True)
            for label,text in [('candidate',source),('mutant',source.replace(*mutation))]:
                path=work/(label+'.c');path.write_text(text);unit=copy.deepcopy(u);unit['source']=str(path)
                for section in unit['sections']:section['address']=number(section['address'])-BASE
                unit['imports']={k:number(v)-BASE for k,v in u.get('imports',{}).items()}
                elf,link=compile_unit(unit,work,[]);sections,exports=link_map(link);segments=elf_segments(elf)
                p=sections['P'];from core import memory_bytes
                data=memory_bytes(segments,p['address'],p['size']);image=bytearray(p['address']+len(data));image[p['address']:]=data
                variants[label]=(bytes(image),{**unit['imports'],**exports})
        unit_result={'byte_comparison':{'equal_bytes':sum(a==b for a,b in zip(variants['retail'][0][address-BASE:],variants['candidate'][0][address-BASE:])),'native_size':length,'candidate_size':len(variants['candidate'][0])-(address-BASE)},'native_sha256':sha(restored),'source_sha256':sha(source.encode()),'rebased_native_pointer_words':patches,'cases':len(selected_cases),'case_names':[case['name'] for case in selected_cases],'inputs':inputs,'simulator_path':str(simulator),'simulator_revision':revision,'variants':{}}
        for label,(image,sym) in variants.items():
            image_path=args.out/(uid+'-'+label+'.bin');image_path.write_bytes(image)
            if uid=='ud2_04':sym={**sym,'_func_pilot_callback':0x710000}
            job={'image':str(image_path.resolve()),'symbols':sym,'entries':{k:v for k,v in sym.items() if k in u['exports']},'cases':selected_cases}
            job_path=args.out/(uid+'-'+label+'.json');job_path.write_text(json.dumps(job))
            run=subprocess.run([args.php,str(HERE/'run.php'),str(simulator),str(job_path)],capture_output=True,text=True,timeout=120)
            if run.returncode:raise RuntimeError(run.stdout+run.stderr)
            rows=json.loads(run.stdout);unit_result['variants'][label]=rows
            print(uid,label,sum(r['passed'] for r in rows),'/',len(rows),flush=True)
            for row in rows:
                if not row['passed']:
                    print(' ',row['case'],row['error'][:220],flush=True);break
        expected_start,expected_size={'tu_0c1e6a68':(address,244),'tu_0c1e8358':(address,52),'tu_0c035160':(address,76),'ud2_04':(0x0c12f9d4,98)}[uid]
        expected=set(range(expected_start-BASE,expected_start-BASE+expected_size))
        covered=set().union(*(set(r.get('executed_bytes',[])) for r in unit_result['variants']['retail']))
        unit_result['native_instruction_coverage']={'covered_bytes':len(expected&covered),'expected_bytes':expected_size,'missing_addresses':[hex(x+BASE) for x in sorted(expected-covered)]}
        for rows in unit_result['variants'].values():
            for row in rows:row.pop('executed_bytes',None)
        original_ok=all(r['passed'] for r in unit_result['variants']['retail'])
        candidate_ok=all(r['passed'] for r in unit_result['variants']['candidate'])
        discriminates=any(not r['passed'] and 'ExpectationException' in r['error'] for r in unit_result['variants']['mutant'])
        all_valid &= original_ok and candidate_ok and discriminates and (bool(args.case) or expected<=covered)
        unit_result['mutation_control']=discriminates
        if fingerprint(u,selected_cases)!=inputs:raise ValueError('Behavioral inputs changed during execution')
        results[uid]=unit_result
    if sha(Path(__file__).read_bytes())!=pilot_hash or sha((HERE/'run.php').read_bytes())!=adapter_hash:raise ValueError('Pilot inputs changed during execution')
    result={'simulator_revision':revision,'main_sha256':sha(main_image),'compiler_options':load(ROOT/'config/compiler.json')['sets']['game'],'adapter_sha256':adapter_hash,'pilot_sha256':pilot_hash,'elapsed_seconds':time.monotonic()-start,'passed':bool(all_valid),'units':results,'acceptance':'Behavioral evidence only; exact-byte gate unchanged.'}
    # Retain independent unit results; their own fingerprints still decide freshness.
    previous=args.out/'results.json'
    if args.unit and previous.exists():
        old=load(previous).get('units',{})
        result['units']={**old,**results}
    result['selected_units']=list(results)
    result['passed_scope']='selected units and cases only'
    (args.out/'results.json').write_text(json.dumps(result,indent=2)+'\n')
    return 0 if all_valid else 1
if __name__=='__main__':sys.exit(main())
