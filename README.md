# Athena

# TODO
- [X] fill 0 and 1 (ndims)
- [X] add tensor data type (dtype) property
- [ ] document supported types
- [ ] Add documentation for "Returns:" and continue to write docs for "Args:" - Rewrite to @param and @return
- [X] matmul 
- [ ] function to return the name of the layer
- [ ] dot product 
- [ ] rename getDim() to dim()
- [ ] input custom tensor object -> TensorImpl<type, size> x({I, J, K})
- [ ] assignment operator -> = 
- [ ] tensor product (outer & inner)
- [X] 2D Transpose 
- [ ] Transpose 
- [ ] Addition/Subtraction/Division/Multiplication
- [X] Sqrt (ndims) 
- [ ] Cbrt 
- [X] squared -> n^2 (ndims) 
- [ ] indexing operator -> [n]...
- [ ] add [ and ] to op::print tensor 
- [ ] rand and randn 
- [ ] item() should return the value at that index and take no parameters
- [ ] flatten() [[], []] -> []
- [ ] unflatten(1, 2, 2) [i, j, k, l, m, n] -> [[i,j,k], [l, m, n]]
