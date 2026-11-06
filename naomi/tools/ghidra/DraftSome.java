// Ghidra headless script: decompile the listed functions only, without whole-image analysis.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.file.*;

public class DraftSome extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Paths.get(args[0]);
        Files.createDirectories(out);
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
        for (int i = 1; i < args.length; i++) {
            Address a = toAddr(Long.parseLong(args[i].substring(2), 16));
            disassemble(a);
            Function fn = getFunctionAt(a);
            if (fn == null) fn = createFunction(a, "func_" + args[i].substring(2));
            DecompileResults r = dec.decompileFunction(fn, 60, monitor);
            String c = (r != null && r.getDecompiledFunction() != null) ? r.getDecompiledFunction().getC() : "/* no decompilation */\n";
            Files.write(out.resolve("func_" + args[i].substring(2) + ".c"), c.getBytes());
            println("wrote " + args[i]);
        }
        dec.dispose();
    }
}
