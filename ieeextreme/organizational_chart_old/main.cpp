/**
 * Recursive Algorithm:
 * self.div_min = max(1, self.all_min - sum([c.all_max for c in children]))
 * self.div_max = self.all_max - sum([c.all_min for c in children])
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;

#define vtype pair<int, int>
#define dmin division.first
#define dmax division.second
#define amin all.first
#define amax all.second
#define unknown 6000000001

struct Node {
    vector<string> children;
    string parent;
    string name;
    vtype division;
    vtype all;
};

map<string, Node> nodes;
set<string> leaves;

void calculateDivisionMin(Node &node);
void calculateDivisionMax(Node &node);
void calculateAllMin(Node &node);
void calculateAllMax(Node &node);

bool defined(vtype value) {
    return value != make_pair(0, 0);
}

bool leaf(Node node) {
    return node.children.size() == 0;
}

void print(vtype value) {
    cout << value.first << " " << value.second << endl;
}

void calculateDivisionMin(Node &node) {
    if (node.dmin == unknown) {
        if (node.parent != "NONE") {
            if (nodes[node.parent].amin != unknown) {
                int result = nodes[node.parent].amin;
                bool t = true;
                for (string childs : nodes[node.parent].children) {
                    if (nodes[childs].name != node.name) {
                        calculateAllMax(nodes[childs]);
                        if (nodes[childs].amax != unknown) {                            
                            result -= nodes[childs].amax;
                        } else {
                            t = false;
                        }
                    }
                }
                if (t) {
                    node.dmin = max(1, result);
                }
            }
        }
    }
}

void calculateDivisionMax(Node &node) {
    if (node.dmax == unknown) {
        if (node.parent != "NONE") {
            if (nodes[node.parent].amax != unknown) {
                int result = nodes[node.parent].amax;
                bool t = true;
                for (string childs : nodes[node.parent].children) {
                    if (nodes[childs].name != node.name) {
                        calculateAllMin(nodes[childs]);
                        if (nodes[childs].amin != unknown) {
                            result -= nodes[childs].amin;
                        } else {
                            t = false;
                        }
                    }
                }
                if (t) {
                    node.dmax = result;
                }
            }
        }
    }
}

void calculateAllMin(Node &node) {
    if (node.amin == unknown) {
        if (leaf(node)) {
            if (node.dmin != unknown) {
                node.amin = node.dmin;
            }
            return;
        }
        int result1 = 0, result2 = 0;
        bool t1 = true, t2 = true;
        if (node.parent != "NONE") {
            if (nodes[node.parent].amin != unknown) {
                result1 = nodes[node.parent].amin;
                for (string childs : nodes[node.parent].children) {
                    if (nodes[childs].name != node.name) {
                        calculateAllMax(nodes[childs]);
                        if (nodes[childs].amax != unknown) {
                            result1 -= nodes[childs].amax;
                        } else {
                            t1 = false;
                        }
                    }
                }
                if (t1) {
                    if (nodes[node.parent].dmax != unknown) {
                        result1 -= nodes[node.parent].dmax;
                    } else {
                        t1 = false;
                    }
                }
            }
        }
        if (node.dmin != unknown) {
            result2 = node.dmin;
        } else {
            t2 = false;
        }
        for (string childs : node.children) {
            calculateAllMin(nodes[childs]);
            if (nodes[childs].amin != unknown) {
                result2 -= nodes[childs].amin;
            } else {
                t2 = false;
            }
        }
        if (t1 && t2) {
            node.amin = max(result1, result2);
        } else if (t1) {
            node.amin = result1;
        } else if (t2) {
            node.amin = result2;
        }
    }
}

void calculateAllMax(Node &node) {
    if (node.amax == unknown) {
        if (leaf(node)) {
            if (node.dmax != unknown) {
                node.amax = node.dmax;
            }
            return;
        }
    }
    int result1 = 0, result2 = 0;
    bool t1 = true, t2 = true;
    if (node.parent != "NONE") {
        if (nodes[node.parent].amax != unknown) {
            for (string childs : nodes[node.parent].children) {
                if (nodes[childs].name != node.name) {
                    calculateAllMin(nodes[childs]);
                    if (nodes[childs].amin != unknown) {
                        result1 -= nodes[childs].amin;
                    } else {
                        t1 = false;
                    }
                }
            }
            if (t1) {
                if (nodes[node.parent].dmin != unknown) {
                    result1 -= nodes[node.parent].dmin;
                } else {
                    t1 = false;
                }
            }
        }
        if (node.dmax != unknown) {
            result2 = node.dmax;
        } else {
            t2 = false;
        }
        for (string childs : node.children) {
            calculateAllMax(nodes[childs]);
            if (nodes[childs].amax != unknown) {
                result2 -= nodes[childs].amax;
            } else {
                t2 = false;
            }
        }
        if (t1 && t2) {
            node.amax = min(result1, result2);
        } else if (t1) {
            node.amax = result1;
        } else if (t2) {
            node.amax = result2;
        }
    }
}

// TODO: Integrate Calculate
int main() {
    scanf("%d %d", &N, &Q);
    // Read and construct
    for (int i = 0; i < N; ++i) {
        string name, parent;
        int size1, size2;
        cin >> name >> parent >> size1 >> size2;
        nodes[name].parent = parent;
        leaves.insert(name);
        // initialize leaves
        if (leaves.find(parent) != leaves.end()) {
            leaves.erase(parent);
        }
        nodes[parent].children.push_back(parent);
        if (size1 != 0) {
            nodes[name].division = make_pair(size1, size1);
        } else {
            nodes[name].division = make_pair(unknown, unknown);
        }
        if (size2 != 0) {
            nodes[name].all = make_pair(size2, size2);
        } else {
            nodes[name].all = make_pair(unknown, unknown);
        }
    }
    // process leaves
    for (string name : leaves) {
        if (defined(nodes[name].all)) {
            nodes[name].division = nodes[name].all;
        }
        if (defined(nodes[name].division)) {
            nodes[name].all = nodes[name].division;
        }
    }
    // compute determined values
    calculateDivisionMin(nodes[nodes["NONE"].children[0]]);
    // print results
    for (int i = 0; i < Q; ++i) {
        string name, type;
        cin >> name >> type;
        if (type == "1") {
            print(nodes[name].division);
        } else if (type == "2") {
            print(nodes[name].all);
        }
    }
    return 0;
}

