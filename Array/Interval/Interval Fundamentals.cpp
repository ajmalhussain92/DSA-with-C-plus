

/*

1. The golden rule: Sort first

	sort (intervals.begin(), intervals.end());

	-> This sorts by:	start first, then end

		Before:

		[5, 7]
		[1, 3]
		[2, 6]
		[10, 12]

		After:

		[1, 3]
		[2, 6]
		[5, 7]
		[10, 12]

	-> Now we can process intervals from left to right.

-----------------------------------------------------------------------------
2. Overlap condition

	-> Overlap:		c <= b		(if holds true)
	-> No overlap:	c <= b		(if holds false)

	where,
		A = [a, b]
		B = [c, d]


	Examples:

			[1, 5]
			[3, 7]

			3 <= 5		Overlap

			But:

			[1, 5]
			[6, 9]

			6 <= 5  	No overlap.

-----------------------------------------------------------------------------
3. The most important boundary question: < or <=?

Consider:

[1, 5]
[5, 10]

Do these overlap?

Mathematically, if intervals are closed:

[1,5] and [5,10]

they touch at 5.

So:

5 <= 5

means they overlap/touch.

Therefore merge:

[1,10]

But some problems consider touching intervals as non-overlapping.

-----------------------------------------------------------------------------
4. Don't confuse "overlap" with "containment"

Consider:

[1, 10]
[3, 5]

The second interval is completely inside the first.

They overlap.

The merged interval is still:

[1,10]

That's why this is important:

ans.back()[1] = max(ans.back()[1], interval[1]);

Not:

ans.back()[1] = interval[1]; 		// WRONG

-----------------------------------------------------------------------------
5. For "Remove Minimum Intervals", the strategy changes

This is where many people make a mistake.

Suppose:

[1,3]
[2,4]
[3,5]
[6,7]

The problem may ask:

Remove the minimum number of intervals so that the remaining intervals don't overlap.

You don't merge here.

Instead, think:

When two intervals overlap, which one should I keep?

Keep the one that ends earlier.

Why?

Because it leaves more room for future intervals.

-----------------------------------------------------------------------------


*/