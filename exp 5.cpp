#include "design.h"

int sc_main(int argc, char* argv[]) {
    sc_clock clock("clock", 10, SC_NS, 0.5, 5, SC_NS, true);
    ConcurrentProcesses dut("dut");
    dut.clk(clock);
    std::cout << "Experiment 5: Clock-Driven Concurrent Processes\n";
    sc_start(51, SC_NS);
    std::cout << "Produced: " << dut.produced
              << " | Consumed: " << dut.consumed << '\n';
    return (dut.produced == 5 && dut.consumed == 5) ? 0 : 1;
}
