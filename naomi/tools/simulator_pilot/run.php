<?php
// Use upstream's instruction engine and expectation matcher without its CLI dependencies.
$root = $argv[1];
spl_autoload_register(function ($class) use ($root) {
    $prefix = 'Lhsazevedo\\Sh4ObjTest\\';
    if (str_starts_with($class, $prefix)) {
        require $root . '/src/' . str_replace('\\', '/', substr($class, strlen($prefix))) . '.php';
    }
});
use Lhsazevedo\Sh4ObjTest\Test\{Run, TestCaseDTO, LinkedProgram, MemoryInitialization, NullEventListener};
use Lhsazevedo\Sh4ObjTest\Test\Expectations\{CallCommand, CallExpectation, WriteExpectation, ReturnExpectation};
use Lhsazevedo\Sh4ObjTest\Simulator\{Symbol, SymbolTable};
use Lhsazevedo\Sh4ObjTest\Simulator\Types\U32;
class BoundedListener extends NullEventListener {
    public int $steps = 0;
    public function onDisasm(string $message): void {
        if (++$this->steps > 100000) throw new RuntimeException('Instruction budget exceeded');
    }
}
$job = json_decode(file_get_contents($argv[2]), true, flags: JSON_THROW_ON_ERROR);
$symbols = new SymbolTable();
foreach ($job['symbols'] as $name => $address) {
    $symbols->addSymbol(new Symbol($name, U32::of($address), str_starts_with($name, '_func_')));
}
$program = new LinkedProgram(file_get_contents($job['image']), $symbols, [], $job['entries']);
$results = [];
foreach ($job['cases'] as $case) {
    $init = array_map(fn($r) => new MemoryInitialization($r[0], $r[1], $r[2]), $case['initializations']);
    $expectations = [(new CallCommand($case['entry']))->with(...$case['arguments'])];
    foreach ($case['expectations'] as $e) {
        if ($e['kind'] === 'return') $expectations[] = new ReturnExpectation($e['value']);
        elseif ($e['kind'] === 'write') $expectations[] = new WriteExpectation($e['address'], $e['value'], $e['size']);
        elseif ($e['kind'] === 'call') {
            $call = (new CallExpectation($e['symbol'], $job['symbols'][$e['symbol']]))->with(...$e['arguments']);
            if (isset($e['variadic_fixed'])) $call->variadic($e['variadic_fixed']);
            if (isset($e['return'])) $call->andReturn($e['return']);
            $expectations[] = $call;
        } else throw new RuntimeException('Unknown expectation');
    }
    $listener = new BoundedListener();
    $dto = new TestCaseDTO($case['name'], $job['image'], $program, $init, [], $expectations, [], [], true, false);
    try {
        $result = (new Run($listener, $dto, true))->run();
        $results[] = ['case'=>$case['name'], 'passed'=>true, 'steps'=>$listener->steps, 'executed_bytes'=>$result->coverage->toArray()['execute']];
    } catch (Throwable $e) {
        $results[] = ['case'=>$case['name'], 'passed'=>false, 'error'=>get_class($e).': '.$e->getMessage(), 'steps'=>$listener->steps];
    }
}
echo json_encode($results, JSON_PRETTY_PRINT | JSON_THROW_ON_ERROR), "\n";
