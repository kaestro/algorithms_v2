# Basic format of starting comment

1. write where the problem is from
    ex) leetcode.com/abcdefg
    * you may add name of the question too
2. write down what type of algorithm you've used to solve it
    ex) dijkstra's algorithm
3. write down date:
    ex) 09.21.2020
4. purpose:
    ex) review, first time
    -> will be used to update findAddressMatchingAns.cmd
    -> it will then not show those with "review" tags as default


# findAddressMatchingAns.cmd

Can only use with windows.
Run the script, giving the address of the problem as its argument.

ex) https://programmers.co.kr/learn/courses/30/lessons/60059
If you've solved the problem above, then,

findAddressMatchingAns https://programmers.co.kr/learn/courses/30/lessons/60059

will find the filename of the source code you've written before.