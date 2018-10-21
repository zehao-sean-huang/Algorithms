/**
 * Recursive Algorithm:
 * self.div_min = max(1, self.all_min - sum([c.all_max for c in children]))
 * self.div_max = self.all_max - sum([c.all_min for c in children])
 *
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;

#define unknown 6000000001
#define ll long long

struct Node {
    vector<string> children;
    string parent;
    string name;
    ll dmin;
    ll dmax;
    ll amin;
    ll amax;
};

map<string, Node> nodes;
set<string> leaves;

void calculateDivisionMin(Node &node);
void calculateDivisionMax(Node &node);
void calculateAllMin(Node &node);
void calculateAllMax(Node &node);

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll min(ll a, ll b) {
    return a < b ? a : b;
}

bool leaf(Node node) {
    return node.children.size() == 0;
}

void calculateDivisionMin(Node &node) {
    if (node.dmin == unknown) {
        if (leaf(node)) {
            if (node.amin == unknown) {
                node.dmin = 1;
            } else {
                node.dmin = node.amin;
            }
            return;
        }
        if (node.parent != "NONE") {
            if (nodes[node.parent].amin != unknown) {
                ll result = nodes[node.parent].amin;
                bool t = true;
                for (string childs : node.children) {
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
                    node.dmin = result > 1 ? result : 1;
                } else {
                    node.dmin = 1;
                }
            }
        }
    }
}

void calculateDivisionMax(Node &node) {
    if (node.dmax == unknown) {
        if (leaf(node)) {
            if (node.amax != unknown) {
                node.dmax = node.amax;
            }
        }
        if (node.parent != "NONE") {
            if (nodes[node.parent].amax != unknown) {
                ll result = nodes[node.parent].amax;
                bool t = true;
                for (string childs : node.children) {
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
        ll result1 = 0, result2 = 0;
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
        ll result1 = 0, result2 = 0;
        bool t1 = true, t2 = true;
        if (node.parent != "NONE") {
            if (nodes[node.parent].amax != unknown) {
                result1 = nodes[node.parent].amax;
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
}

void calculate(Node &node) {
    calculateAllMin(node);
    calculateAllMax(node);
    calculateDivisionMin(node);
    calculateDivisionMax(node);
    for (string childs : node.children) {
        calculate(nodes[childs]);
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
        nodes[name].name = name;
        leaves.insert(name);
        // initialize leaves
        if (leaves.find(parent) != leaves.end()) {
            leaves.erase(parent);
        }
        nodes[parent].children.push_back(name);
        if (size1 != 0) {
            nodes[name].dmin = size1;
            nodes[name].dmax = size1;
        } else {
            nodes[name].dmin = unknown;
            nodes[name].dmax = unknown;
        }
        if (size2 != 0) {
            nodes[name].amin = size2;
            nodes[name].amax = size2;
        } else {
            nodes[name].amin = unknown;
            nodes[name].amax = unknown;
        }
    }
    // compute determined values
    string root = nodes["NONE"].children[0];
    calculate(nodes[root]);
    // prll results
    for (int i = 0; i < Q; ++i) {
        string name, type;
        cin >> name >> type;
        if (type == "2") {
            cout << nodes[name].amin << " " << nodes[name].amax << endl;
        } else if (type == "1") {
            cout << nodes[name].dmin << " " << nodes[name].dmax << endl;
        }
    }
    return 0;
}
