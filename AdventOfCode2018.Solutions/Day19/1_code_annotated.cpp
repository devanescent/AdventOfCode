goto init; // r2 += 16;					// [0] addi 2 16 2

main_loop:
r5 = 1;									// [1] seti 1 8 5

outer_loop:
r3 = 1;									// [2] seti 1 0 3

inner_loop:
r4 = r5 * r3;							// [3] mulr 5 3 4

// In part 1, r1 is 892. In part 2, r1 is 10.551.292

// r4 = (r4 == r1) ? 1 : 0;				// [4] eqrr 4 1 4
// r2 += r4;							// [5] addr 4 2 2
// r2 += 1;								// [6] addi 2 1 2
// r0 += r5;							// [7] addr 5 0 0

// (r4 == r1) sets r4 to 1, which after adding it to r2 in [5] effectively skips [6] (which would skip [7]),
// so [7] actually executes and the above 4 instructions translate to:
if (r4 == r1)
	r0 += r5;

++r3;									// [8] addi 3 1 3

// r4 = (r3 > r1) ? 1 : 0;				// [9] gtrr 3 1 4
// r2 += r4;							// [10] addr 2 4 2
// r2 = 2;								// [11] seti 2 1 2
if (r3 <= r1)
	goto inner_loop;

++r5;									// [12] addi 5 1 5

// r4 = (r5 > r1) ? 1 : 0;				// [13] gtrr 5 1 4
// r2 += r4;							// [14] addr 4 2 2
// r2 = 1;								// [15] seti 1 1 2
if (r5 <= r1)
	goto outer_loop;

return; // r2 *= r2;					// [16] mulr 2 2 2 		// HALT instruction, r2 is set to 16 * 16, which is outside of the program

init:
r1 += 2;								// [17] addi 1 2 1		// r1 = 2
r1 *= r1;								// [18] mulr 1 1 1		//
r1 *= 19; // r1 *= r2;					// [19] mulr 2 1 1		//
r1 *= 11;								// [20] muli 1 11 1		// r1 = (2 * 2) * 19 * 11 = 836;

r4 += 2;								// [21] addi 4 2 4		//
r4 *= 22; // r4 *= r2;					// [22] mulr 4 2 4		//
r4 += 12;								// [23] addi 4 12 4		// r4 = ((r4 + 2) * 22) + 12;
																// Initially, r4 == 0 -> r4 = 2 * 22 + 12 = 56;

r1 += 56; // r1 += r4;					// [24] addr 1 4 1		// r1 = 836 + 56 = 892

r2 += r0;								// [25] addr 2 0 2		// part 2: r0 is initialized to 1, effectively skipping [26] on first arrival at this instruction
goto main_loop;	// r2 = 0;				// [26] seti 0 9 2		// so the IP does not jump back to the top, but continues executing lines below

r4 = 27; // r4 = r2;					// [27] setr 2 3 4		// following lines are some kind of additional "initialization" happening before the main loop
r4 *= 28; // r4 *= r2;					// [28] mulr 4 2 4
r4 += 29; // r4 += r2;					// [29] addr 2 4 4
r4 *= 30; // r4 *= r2;					// [30] mulr 2 4 4
r4 *= 14;								// [31] muli 4 14 4
r4 *= 32; // r4 *= r2;					// [32] mulr 4 2 4		// r4 = ((27 * 28) + 29) * 30 * 14 * 32 = 10'550'400;

r1 += 10'550'400; // r1 += r4;			// [33] addr 1 4 1		// r1 = 892 + 10'550'400 = 10.551.292

r0 = 0;									// [34] seti 0 1 0		// afterwards, execute like part 1, but with the additonal code ([27] - [33]) executed before

goto main_loop;	// r2 = 0;				// [35] seti 0 4 2		// same effect as [26] in part 1, jumps back to top