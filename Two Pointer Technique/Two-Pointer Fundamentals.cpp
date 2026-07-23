
// Use two indices.
// Then move them according to the problem.


/* Type 1: Opposite Direction ----------------------- */

int left = 0;
int right = n - 1;

while (left < right)
{
    if (...)
        left++;
    else
        right--;
}



/* Type 2: Same Direction -------------------------- */

int left = 0;
int right = 0;


/*

Arrays & Strings
        │
        ▼
Two Pointer Technique
        │
        ├── Opposite Direction Two Pointers
        │
        ├── Same Direction Two Pointers
        │        │
        │        └── Sliding Window
        │
        └── Fast & Slow Pointers (Linked Lists)

---------------------------------------------------------------

Sliding Window is just a specialized Two Pointer technique
Instead of randomly moving pointers, you maintain a window.

---------------------------------------------------------------
Types of Sliding Window

	1. Fixed Size Window
		Window size never changes.

	2. Variable Size Window
		Here the window grows and shrinks.



*/