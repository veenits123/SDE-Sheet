#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/edge_coloring.hpp>
#include <boost/graph/properties.hpp>
#include <iostream>

#define pgr_vertex_color_rt pair<int,int>

using namespace boost;
using namespace std;


// namespace pgrouting {
// namespace functions {

//*************************************************************

template < class G >
class Pgr_edgeColoring {
public:
    typedef typename boost::graph_traits < G >::vertex_descriptor V;
    typedef typename boost::graph_traits < G >::edge_descriptor E;

    //typedef typename G::V V;
    //typedef typename G::E E;

    //#new
    typedef adjacency_list< vecS, vecS, undirectedS, no_property, size_t,
            no_property >
            Graph;

    // typedef boost::adjacency_list < boost::listS, boost::vecS, boost::undirectedS > Graph;
    typedef boost::graph_traits < Graph > ::edges_size_type edges_size_type;

    /** @name EdgeColoring
     * @{
     *
     */

    /** @brief edgeColoring function
     *
     * It does all the processing and returns the results.
     *
     * @param graph      the graph containing the edges
     *
     * @returns results, when results are found
     *
     * @see [boost::edge_coloring]
     * (https://www.boost.org/libs/graph/doc/edge_coloring.html)
     */
    std::vector < pgr_vertex_color_rt > edgeColoring(G &graph) {
        std::vector < pgr_vertex_color_rt > results;

        auto i_map = boost::get(boost::edge_bundle, graph);

        // vector which will store the color of all the edges in the graph
        std::vector < edges_size_type > colors(boost::num_edges(graph));

        // An iterator property map which records the color of each edge
        auto color_map = boost::make_iterator_property_map(colors.begin(), i_map);

        /* abort in case of an interruption occurs (e.g. the query is being cancelled) */
        // CHECK_FOR_INTERRUPTS();

        try {
            boost::edge_coloring(graph, color_map);
        } catch (boost::exception const& ex) {
            (void)ex;
            throw;
        } catch (std::exception &e) {
            (void)e;
            throw;
        } catch (...) {
            throw;
        }

        results = get_results(colors, graph);

        return results;
    }

    //@}

private:
    /** @brief to get the results
     *
     * Uses the `colors` vector to get the results i.e. the color of every edge.
     *
     * @param colors      vector which contains the color of every edge
     * @param graph       the graph containing the edges
     *
     * @returns `results` vector
     */
    std::vector < pgr_vertex_color_rt > get_results(
        std::vector < edges_size_type > &colors,
        const G &graph) {
        std::vector < pgr_vertex_color_rt > results;

        typename boost::graph_traits < Graph > ::edge_iterator e_i, e_end;

        for (boost::tie(e_i, e_end) = edges(graph); e_i != e_end; ++e_i) {
            int64_t edge = graph[*e_i];

            // auto src = source(*e_i, graph.graph);
            // auto tgt = target(*e_i, graph.graph);

            int64_t color = colors[edge];

            results.push_back({ edge, (color + 1) });
        }

        std::sort(results.begin(), results.end(),
        [](const pgr_vertex_color_rt row1, const pgr_vertex_color_rt row2) {
            return row1.first < row2.first;
        });

        return results;
    }
};
// }  // namespace functions
// }  // namespace pgrouting

int main(int, char*[]) {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    typedef adjacency_list<vecS, vecS, undirectedS, no_property, size_t,
            no_property>
            Graph;

    typedef std::pair<std::size_t, std::size_t> Pair;
    Pair edges[14] = {Pair(1, 4),
                      Pair(1, 6),
                      Pair(2, 3),
                      Pair(2, 5),
                      Pair(2, 7),
                      Pair(2, 10),
                      Pair(3, 4),
                      Pair(3, 5),
                      Pair(4, 6),
                      Pair(4, 9),
                      Pair(5, 7),
                      Pair(6, 7),
                      Pair(6, 8),
                      Pair(7, 8)
                     };

    Graph G(10);

    for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); i++)
        add_edge(edges[i].first, edges[i].second, G);

    size_t colors = edge_coloring(G, get(edge_bundle, G));

    // cout << "Colored using " << colors << " colors" << endl;

    // for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
    //     cout << "  " << edges[i].first << "-"
    //          << edges[i].second << ": "
    //          << G[edge(edges[i].first, edges[i].second, G).first] + 1 << endl;
    // }


    auto ans = Pgr_edgeColoring <Graph>().edgeColoring(G);

    for (auto x : ans)
        cout << x.first << " " << x.second << endl;


    return 0;
}