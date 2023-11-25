# Monster embeddings of certain 3-transposition groups via Majorana representations

To find out the `Matrix B` from the corresponding paper, one may run `main.cpp`. Results will be displayed in lmatrix.txt in a format acceptable by GAP. The fact that the matrix B is not positive semidefinite can be verified by the following straightforward way.

``` 
A:= (result from lmatrix.txt);
p:=CharacteristicPolynomial(A);
Factors(p);
```

The result shows that -1.5 is an eigenvalue for B.