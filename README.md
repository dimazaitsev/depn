# depn

Generator of Petri nets which count double exponent 2^2^k after R.J.Lipton & J.Esparza constructs


Description:
------------

The generated net counts 2^2^k as a strong computer after Richard J. Lipton [1]. 

Well-structured net programs of Javier Esparza [2] have been encoded by Petri nets.

The following marking belongs to the reachability space: fin-INC_k=1; x_0=2, y_0=2, s'_0=2; x_1=4, y_1=4, s'_1=4; ...; x_k=2^2^k, y_k=2^2^k, s'_k=2^2^k. It is the only marking with fin-INC_k>0.

For a given k, the resulting net is composed of a single Block_0 and repeated (k-1) times Block_i. 

Block_i includes subnets INC_{i+1}, TST-y_i, TST-x_i, DEC_i and variables (places) x_i, x'_i, y_i, y'_i, s_i, s'_i.

Connections of neighboring blocks reflect initialization of the next variables ```x_{i+1}```, ```y_{i+1}```, ```s'_{i+1}``` and recursive calls of the previous block's ```TST-y_{i-1}```, ```TST-x_{i-1}```:

```
                                                 x_{i+1}
                                       +----->   y_{i+1}
                                       |        s'_{i+1} 
                                       |
    +-------------+             +------+------+
+---| INC_i       |============>| INC_{i+1}   |---+
|   +-------------+             +-------------+   |
|                                                 |
|   +-------------+             +-------------+   |
+-->| TST-y_{i-1} |<------+     | TST-y_i     |<--+
|   +-------------+       |     +-------------+   |
|          |              |            |          |
|          v              |            V          |
|   +-------------+       |     +-------------+   |
|   | DEC_{i-1}   |       +-----| DEC_i       |   |
|   +-------------+       |     +-------------+   |
|          ^              |            ^          |
|          |              |            |          |
|   +-------------+       |     +-------------+   |
+-->| TST-x_{i-1} |<------+     | TST-x_i     |<--+
    +-------------+             +-------------+
```

Peculiarities of generating Petri nets in logical (.net) and graphical (.ndr) formats of system Tina are described in [3].


Command line formats:
--------------------

>depn k > pn_de_k.ndr


Parameters:
-----------

k   an exponent to count 2^2^k (k>0).


Output (file) format:
---------------------

.ndr  "Time Petri nets graphic format" according to http://www.laas.fr/tina


Tools to display, edit, visualize, and analyze generated models:
----------------------------------------------------------------

Tina Toolbox for analysis of Petri nets and Time Petri nets http://www.laas.fr/tina

Small nets (k<=3) can be analyzed in graphical tool nd. For bigger nets we recommend using command line tools: sift - to build the marking graph and muse - to find required marking.

Exported from Tina, models are opened with other tools for Petri nets listed at http://www.informatik.uni-hamburg.de/TGI/PetriNets/tools/quick.html


Examples:
---------

A. Graphical environment

>depn 2 > pn_de_2.ndr

- Generate Petri net to count 2^2^2=16

>nd pn_de_2.ndr

- Load the net into graphical environment of Tina. 

Menue: "Tools - reachability analysis - verbose - OK"

- Create marking graph

- Save marking graph into file pn_de_2-tina-R.txt

- Find the only marking having a token in place ```fin-INC_2 (p72)```: ```p8*2 p10*2 p13*2 p55*4 p56*4 p57*4 p108*16 p109*16 p110*16 p72```


B. Command line tools

>depn 3 > pn_de_3.ndr

- Generate Petri net to count 2^2^3=256

>sift pn_de_3.ndr -f "-p125"

- Build the marking graph and search on-fly for markings which contain a token in p125 (fin-INC_3).

To start a search in a marking graph, we can determine the place number n (for the label ```fin-INC_k```) either from graphical representation of the net in nd or via textual search on .ndr file for a given label or using the following expression based on the number of places in ```Block_0``` and ```Block_i``` and offsets of the place in question within blocks: if k=1 then n=25 else n=54+(k-2)*53+18=53k-34. Note that marking graphs are rather big to tackle with them for k>4.

References:
-----------

1. Richard J. Lipton, The Reachability Problem Requires Exponential Space, Technical Report 63, Yale University, 1976. http://www.cs.yale.edu/publications/techreports/tr63.pdf

2. Javier Esparza, Decidability and Complexity of Petri Net Problems - An Introduction. LNCS 1491, 1996, 374-428. http://www7.in.tum.de/um/bibdb/esparza/course.pdf  

3. Dmitry A. Zaitsev, Generators of Petri Net Models. Computer Communication & Collaboration, Vol. 2, Issue 2, 2014, 12-25. http://www.bapress.ca/ccc/ccc2014_2/2_14011024.pdf


---------------------------
http://member.acm.org/~daze
---------------------------

