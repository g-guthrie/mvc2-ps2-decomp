// Ghidra headless script: create functions at the reviewed starts, mark pools as data,
// and write one decompiled draft per function. No whole-image analysis: the map
// already says where code and data are, and per-function decompilation is fast.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class DraftExport extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path spec = Paths.get(args[0]);
        Path out = Paths.get(args[1]);
        Files.createDirectories(out);
        List<String> lines = Files.readAllLines(spec);
        for (String line : lines) {
            String[] f = line.trim().split("\\s+");
            if (f.length < 3) continue;
            Address a = toAddr(Long.parseLong(f[0].substring(2), 16));
            int size = Integer.parseInt(f[1]);
            if (f[2].equals("data")) {
                try { createData(a, new ArrayDataType(ByteDataType.dataType, size, 1)); } catch (Exception e) {}
            } else if (f[2].equals("function")) {
                disassemble(a);
                if (getFunctionAt(a) == null) createFunction(a, "func_" + f[0].substring(2));
            } else {
                disassemble(a);
            }
        }
        for (ghidra.program.model.mem.MemoryBlock block : currentProgram.getMemory().getBlocks()) block.setWrite(false);
        // The game runs the FPU in single precision with 32-bit moves; tell the decompiler so.
        ghidra.program.model.listing.ProgramContext ctx = currentProgram.getProgramContext();
        ghidra.program.model.address.Address lo = currentProgram.getMinAddress(), hi = currentProgram.getMaxAddress();
        for (String rn : new String[]{"FPSCR_PR", "FPSCR_SZ", "FPSCR_FR"}) {
            ghidra.program.model.lang.Register reg = ctx.getRegister(rn);
            if (reg != null) ctx.setRegisterValue(lo, hi, new ghidra.program.model.lang.RegisterValue(reg, java.math.BigInteger.ZERO));
        }
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0;
        try (PrintWriter index = new PrintWriter(out.resolve("index.txt").toFile())) {
            while (it.hasNext()) {
                Function fn = it.next();
                DecompileResults r = dec.decompileFunction(fn, 60, monitor);
                String c = (r != null && r.getDecompiledFunction() != null) ? r.getDecompiledFunction().getC() : "/* no decompilation */\n";
                String name = String.format("func_%08x", fn.getEntryPoint().getOffset());
                long end = fn.getBody().getMaxAddress().getOffset() + 1;
                Files.write(out.resolve(name + ".c"), ("/* " + name + " 0x" + String.format("%08x", fn.getEntryPoint().getOffset()) + "-0x" + String.format("%08x", end) + " Ghidra draft; not source */\n" + c).getBytes());
                index.println(String.format("%s 0x%08x %d", name, fn.getEntryPoint().getOffset(), end - fn.getEntryPoint().getOffset()));
                n++;
            }
        }
        dec.dispose();
        println("wrote " + n + " drafts");
    }
}
