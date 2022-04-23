Let's review the template for two-dimensional difference. Suppose the two-dimensional matrix is ​​f[i][j]. We construct the corresponding difference array diff[i][j]. If we want to uniformly add val to the rectangular area with (x0, y0) as the upper left corner and (x1, y1) as the lower right corner, then we only need mark on diff array：

```
diff[x0][y0]+=1;
diff[x0][y1+1]-=1;
diff[x1+1][y0]-=1;
diff[x1+1][y1+1]+=1;
```

The physical meaning of diff[i][j] is to take (i, j) as the upper left corner and extend to the lower right corner of the large matrix (that is, the entire space), and we assign such an area as a whole.  

Such operations can be performed multiple times. If we want to reconstruct the updated value of f, we need to do the following:  

```cpp
for (int i=0; i<m; i++)
    for (int j=0; j<n; j++)
    {               
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + diff[i][j];
    }
```

At this point, any value in any f can be output. Note that, as can be seen from the above formula, the dimension of the diff array is a bit larger than f. When calculating f, if an out-of-bounds grid is encountered, the default value is 0.

Three methods of template code:

1. Diff2d(vector<vector<int>>& A) is initialized according to the given matrix dimensions (the value of A itself is useless)
2. void set(int x0, int y0, int x1, int y1, int val) will uniformly add val to the rectangular area with (x0, y0) as the upper left corner and (x1, y1) as the lower right corner.
3. This step must be done before void compute() outputs the reconstructed two-dimensional array.
4. f[i][j] directly outputs any value of the reconstructed two-dimensional array.
