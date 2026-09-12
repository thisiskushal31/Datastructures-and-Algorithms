// Practice : https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

// Editorial : https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

import java.util.*;

class GetUnion {
	static void getUnion(int a[], int n, int b[], int m) {

		// Defining set container s
		HashSet<Integer> s = new HashSet<>();

		// Inserting array elements in s
		for (int i = 0; i < n; i++)
			s.add(a[i]);

		for (int i = 0; i < m; i++)
			s.add(b[i]);
		System.out.print("Number of elements after union operation: " + s.size() + "\n");
		System.out.print("The union set of both arrays is :" + "\n");

		System.out.print(s.toString() + " "); // s will contain only distinct
		// elements from array a and b
	}

	// Driver Code
	public static void main(String[] args) {
		int a[] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
		int b[] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };

		getUnion(a, 9, b, 10);
	}
}