int main()
{
	int r0,r1,r2,r3,r4,r5;
	r0 = r1 = r2 = r2 = r4 = r5 = 0;

	// for part 2:
	r0 = 1;

	// Init (part 1 & 2)
	r1 = 836;
	r4 = 56;
	r1 += r4;

	if (r0 == 1) // only part 2
	{
		r4 = 10'550'400;
		r1 += r4;
	}

	r0 = 0;
	
	// main_loop
	// In part 1, r1 is 892. In part 2, r1 is 10'551'292
	for (r5 = 1; r5 <= r1; ++r5)
	{
		// inner_loop:
		for (r3 = 1; r3 <= r1; ++r3)
		{
			r4 = r5 * r3;

			// Sums up all divisors of the given target number (r1) into r0:
			if (r4 == r1)
				r0 += r5;
		}
	}

	return 0;
}