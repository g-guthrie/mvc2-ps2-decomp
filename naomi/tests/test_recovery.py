import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools'))
from recovery import prioritize, disjoint_batch, record, read_journal, experiment_state, search_context
from permute import bounded_search, search_outcome

class RecoveryTests(unittest.TestCase):
    def test_new_code_not_raw_closeness_drives_priority(self):
        rows=[dict(id='two_byte_puzzle',address=10,kind='near_match',new_code_bytes=20,diagnosis={'category':'register_choice'}),
              dict(id='new_family',address=20,kind='untouched',new_code_bytes=600)]
        self.assertEqual(prioritize(rows)[0]['id'],'new_family')
        next(r for r in rows if r['id']=='two_byte_puzzle')['experiment']={'status':'needs_new_evidence'}
        stalled=dict(id='stalled_large',address=30,kind='untouched',new_code_bytes=5000,experiment={'status':'needs_new_evidence'})
        self.assertEqual(prioritize(rows+[stalled])[-1]['experiment']['status'],'needs_new_evidence')

    def test_batch_excludes_overlap_blocked_and_parked(self):
        rows=[dict(id='a',address=0,expected_bytes=100,ranges=[(0,100)]),
              dict(id='overlap',address=90,expected_bytes=30),
              dict(id='blocked',address=200,expected_bytes=40,boundaries={'issues':['incoming']}),
              dict(id='parked',address=300,expected_bytes=40,experiment={'status':'needs_new_evidence'}),
              dict(id='b',address=400,expected_bytes=40)]
        self.assertEqual([r['id'] for r in disjoint_batch(rows,['one','two'])],['a','b'])

    def test_stall_is_bound_to_source_and_new_evidence_unparks(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'unit.c').write_text('old')
            unit={'id':'unit','source':'unit.c'};key=hashlib.sha256(b'old').hexdigest()
            row={'id':'unit','source_sha256':key,'outcome':'stalled','attempts':10,'minutes':3}
            record(row,root);self.assertEqual(experiment_state(unit,read_journal(root),root)['status'],'needs_new_evidence')
            record({**row,'outcome':'evidence','evidence':'native prototype recovered','attempts':0},root)
            self.assertEqual(experiment_state(unit,read_journal(root),root)['status'],'active')
            (root/'unit.c').write_text('new')
            self.assertEqual(experiment_state(unit,read_journal(root),root)['status'],'untried')

    def test_search_budget_and_persistent_failed_trials(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'build').mkdir();path=root/'unit.c';path.write_text('original')
            initial={'exact':False,'sections':[{'equal_bytes':1}]};calls=[]
            def evaluate(p,descriptor):
                calls.append(Path(p).read_text())
                self.assertEqual(path.read_text(),'original')
                return {'exact':False,'sections':[{'equal_bytes':0}]},descriptor
            with patch('permute.variants',return_value=iter([('a','one'),('b','two'),('c','three')])):
                r=bounded_search(path,{'id':'unit'},initial,budget=2,evaluator=evaluate,root=root)
            self.assertEqual(calls,['one','two']);self.assertEqual(path.read_text(),'original')
            with patch('permute.variants',return_value=iter([('a','one'),('b','two'),('c','three')])):
                r2=bounded_search(path,{'id':'unit'},initial,budget=2,failed=r['failed'],evaluator=evaluate,root=root)
            self.assertEqual(calls,['one','two','three']);self.assertEqual(r2['skipped'],2)

    def test_failed_trial_context_changes_with_facts_and_descriptor(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td)
            for name in ['config/target.json','config/mapping.json','config/runtime.json','config/type_contracts.json','config/units.json','tools/diff_unit.py','tools/permute.py']:
                p=root/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_text('{}')
            unit={'id':'u','source':'a.c','sections':[{'address':'0x1000','size':4}]}
            with patch('build_cache.shared_inputs',return_value='headers-and-compiler'):
                old=search_context(unit,root)
                self.assertEqual(old,search_context(unit,root))
                (root/'config/mapping.json').write_text('{"changed":true}')
                self.assertNotEqual(old,search_context(unit,root))
                current=search_context(unit,root)
                unit['sections'][0]['size']=8
                self.assertNotEqual(current,search_context(unit,root))

    def test_stalled_evidence_expires_with_compiler_context(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'unit.c').write_text('same')
            unit={'id':'u','source':'unit.c'}
            rows=[{'id':'u','source_sha256':hashlib.sha256(b'same').hexdigest(),'context':'old','outcome':'stalled','attempts':10}]
            with patch('recovery.search_context',return_value='new'):
                self.assertEqual(experiment_state(unit,rows,root)['status'],'untried')

    def test_improvement_is_not_negative_cached_and_tool_errors_are_retryable(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'build').mkdir();path=root/'unit.c';path.write_text('original')
            initial={'exact':False,'sections':[{'equal_bytes':1}]}
            def evaluator(p,descriptor):return {'exact':False,'sections':[{'equal_bytes':2}]},descriptor
            with patch('permute.variants',return_value=iter([('a','better')])):
                result=bounded_search(path,{'id':'u'},initial,budget=1,evaluator=evaluator,root=root)
            self.assertEqual(result['failed'],[])
            with patch('permute.variants',return_value=iter([('a','better')])):
                retry=bounded_search(path,{'id':'u'},initial,budget=1,failed=result['failed'],evaluator=evaluator,root=root)
            self.assertEqual(retry['compiled'],1);self.assertEqual(retry['score'],2)
            self.assertEqual(search_outcome({'exact':False,'score':1,'compiled':10,'errors':10},1),'inconclusive')

    def test_later_round_failure_does_not_hide_bridge_after_transient_error(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'build').mkdir();path=root/'unit.c';path.write_text('original')
            initial={'exact':False,'sections':[{'equal_bytes':1}]}
            def candidates(text):
                return iter([('best','best'),('bridge','bridge')]) if text=='original' else iter([('bridge','bridge')])
            def evaluate(p,descriptor):
                value=3 if Path(p).read_text()=='best' else 2
                return {'exact':False,'sections':[{'equal_bytes':value}]},descriptor
            with patch('permute.variants',side_effect=candidates):
                result=bounded_search(path,{'id':'u'},initial,evaluator=evaluate,root=root)
            self.assertEqual(result['failed'],[])
            def transient(p,descriptor):
                if Path(p).read_text()=='best':raise ValueError('temporary compiler failure')
                return evaluate(p,descriptor)
            with patch('permute.variants',side_effect=candidates):
                retry=bounded_search(path,{'id':'u'},initial,failed=result['failed'],evaluator=transient,root=root)
            self.assertEqual(retry['score'],2)

    def test_concurrent_edit_is_preserved(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'build').mkdir();path=root/'unit.c';path.write_text('original')
            def evaluator(p,descriptor):
                path.write_text('user edit');return {'exact':True,'sections':[{'equal_bytes':9}]},descriptor
            with patch('permute.variants',return_value=iter([('a','better')])), self.assertRaisesRegex(ValueError,'Source changed'):
                bounded_search(path,{'id':'u'},{'exact':False,'sections':[{'equal_bytes':1}]},root=root,evaluator=evaluator)
            self.assertEqual(path.read_text(),'user edit')

    def test_interrupted_trial_preserves_source(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'build').mkdir();path=root/'unit.c';path.write_text('original')
            with patch('permute.variants',return_value=iter([('a','changed')])), self.assertRaises(KeyboardInterrupt):
                bounded_search(path,{'id':'unit'},{'exact':False,'sections':[{'equal_bytes':1}]},root=root,
                               evaluator=lambda *a,**k: (_ for _ in ()).throw(KeyboardInterrupt()))
            self.assertEqual(path.read_text(),'original')

    def test_exact_trial_is_actually_evaluated_and_not_negative_cached(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);(root/'build').mkdir();path=root/'unit.c';path.write_text('original');calls=[]
            def evaluator(p,descriptor):
                calls.append(Path(p).read_text());return {'exact':True,'sections':[{'equal_bytes':9}]},descriptor
            with patch('permute.variants',return_value=iter([('a','exact')])):
                result=bounded_search(path,{'id':'unit'},{'exact':False,'sections':[{'equal_bytes':1}]},root=root,evaluator=evaluator)
            self.assertEqual(calls,['exact']);self.assertTrue(result['exact']);self.assertEqual(result['failed'],[])
            self.assertEqual(path.read_text(),'original')

if __name__=='__main__':unittest.main()
