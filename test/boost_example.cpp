#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/edge_coloring.hpp>
#include <boost/graph/properties.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main(int, char*[]) {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    typedef adjacency_list<vecS, vecS, undirectedS, no_property, size_t,
            no_property>
            Graph;

    typedef std::pair<std::size_t, std::size_t> Pair;
    Pair edges[2] = {Pair(1, 2),
                     Pair(3, 4)
                    };

    Graph G(10);

    for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); i++)
        add_edge(edges[i].first, edges[i].second, G);

    size_t colors = edge_coloring(G, get(edge_bundle, G));

    cout << "Colored using " << colors << " colors" << endl;
    for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        cout << "  " << edges[i].first << "-"
             << edges[i].second << ": "
             << G[edge(edges[i].first, edges[i].second, G).first] + 1 << endl;
    }

    return 0;
}