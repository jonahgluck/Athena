# Athena

## TensorImpl properties 

``.get(int index)``
<br>
Returns the item at an index (when indexing a tensor this is ``std::array``)
```cpp
// t is of type TensorImpl<double,3,4>
for(std::size_t i=0; i<t.getDim()[0]; i++) {
  for(std::size_t j=0; j<t.getDim()[1]; j++) {
    std::cout << t.get(i).get(j) << std::endl;
  }
}
```


``.getDim()``
<br>
Returns an ``std::array`` of the order lengths
```cpp
// t is of type TensorImpl<double,3,4>
for(std::size_t i=0; i<t.getDim()[0]; i++) {
  for(std::size_t j=0; j<t.getDim()[1]; j++) {
    std::cout << t.get(i).get(j) << std::endl;
  }
}
```



``.dtype()``
<br>
Returns the type of data stored in the TensorImpl object

If the data type is no known, unknown is returned
```cpp
// t is of type TensorImpl<double,3,4>
for(std::size_t i=0; i<t.getDim()[0]; i++) {
  for(std::size_t j=0; j<t.getDim()[1]; j++) {
    std::cout << t.get(i).get(j).dtype() << std::endl;
  }
}
```


``.item(int index)``
<br>
Prints the item at an index with ``std::cout``
```cpp
// t is of type TensorImpl<double,3,4>
for(std::size_t i=0; i<t.getDim()[0]; i++) {
  for(std::size_t j=0; j<t.getDim()[1]; j++) {
    t.get(i).item(j);
  }
}
```

<hr>

## Operations ``(op::method<type>(params...))``


``op::tpow<type>(t, power)``
<br>
Raises all values in the given tensor to a power
```cpp
// cubed
op::tpow<double>(t, 3);
```


``op::fill<type>(t, value)``
<br>
Fill all of the values in a tensor with a number regardless of the index
```cpp
op::fill<double>(t, 2);
```


``op::print<type>(t)``
<br>
Print all values of a tensor with ``std::cout``
```cpp
op::print<double>(t);
```


``op::randn<type>(t)``
<br>
Fill a tensor with random normal values 
```cpp
op::randn<double>(t);
```

``op::tsqrt<type>(t)``
<br>
Take sqrt of all tensor values 
```cpp
op::tsqrt<double>(t);
```
