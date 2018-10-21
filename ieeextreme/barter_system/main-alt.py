#!/usr/local/bin/python3

class Node:
    
    def __init__(self, name):
        self.name = name
        self.edges = set()
        self.visited = False

class Edge:
    
    def __init__(self, n1, n2, v):
        self.start = n1
        self.end = n2
        self.value = v

def bfs(source, target, value):
    if source is target:
        return value
    for edge in source.edges:
        other = edge.start if edge.start is not source else edge.end
        if other not in visited:
            visited.add(other)
            ret = bfs(other, target, (value * edge.value) % r)
            if ret != -1:
                return ret
    return -1

nodes = dict()
visited = set()
r = 998244353
n = int(input())
for i in range(n):
    line = str(input())
    data = list(line.split(' '))
    com1, com2, conv = data[0], data[1], int(data[2])
    if com1 not in nodes:
        nodes[com1] = Node(com1)
    if com2 not in nodes:
        nodes[com2] = Node(com2);
    edge = Edge(nodes[com1], nodes[com2], conv)
    nodes[com1].edges.add(edge);
    nodes[com2].edges.add(edge);

q = int(input())
for i in range(q):
    line = str(input())
    source = nodes[line.split(' ')[0]]
    target = nodes[line.split(' ')[1]]
    visited.add(source)
    print(bfs(source, target, 1))
    visited.clear()
