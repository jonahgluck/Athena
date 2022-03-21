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

## Operations 


