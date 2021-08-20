 ## Name of the function:

**pgr_edgeColoring()**: Edge Coloring is an algorithm used for coloring of the edges for the vertices in the graph. It is an assignment of colors to the edges of the graph so that no two adjacent edges have the same color.
It can tell us whether a graph is **Bipartite**. If in a graph, the chromatic number **χ′(G)** i.e. minimum number of colors needed for proper edge coloring of graph is equal to degree **Δ** of the graph, (i.e. **χ′(G) = Δ**) then graph is said to be Bipartite. But, the vice-versa is not always true.

### Main characteristics of the function:

- Applicable for **undirected** and **loop-free** (i.e *no self-loops and no parallel edges*) graphs.
- The graph can be either weighted or unweighted.
- At most **Δ + 1** colors are used, where **Δ** is the degree of the graph.
- The returned rows are ordered in ascending order of the edge value.
- Time complexity of the function is: `O(|E||V|)`
  - where: `|E|` is the number of edges in the graph.
  - `|V|` is the number of vertices in the graph.

### Variants:

- pgr_edgeColoring()

```sql
pgr_edgeColoring(Edges SQL)
RETURNS SET OF (edge_id, color_id)
OR EMPTY SET
```

### Parameters:

Parameter | Type | Description
-------------- | ------- | ---------------
**Edges SQL** | ``TEXT`` | Inner SQL query, as described below.

### Inner Query

**Edges SQL**: It should be an SQL query which should return a set of rows with the following columns:

Column | Type | Default | Description
---------- | ------- | --------- | ----------------
**id** | ``ANY-INTEGER`` | | Identifier of the edge
**source** | ``ANY-INTEGER`` | | Identifier of the first end point vertex of the edge
**target** | ``ANY-INTEGER`` | | Identifier of the second end point vertex of the edge
**cost** | ``ANY-NUMERICAL`` | | Weight of the edge (source, target). When negative: edge `(source, target)` does not exist on the graph.
**reverse_cost** | ``ANY-NUMERICAL`` | -1 | Weight of the edge (target, source). When negative: edge `(target, source)` does not exist on the graph.

Where:
``ANY-INTEGER``  =  SMALLINT, INTEGER, BIGINT
``ANY-NUMERICAL``  =  SMALLINT, INTEGER, BIGINT, REAL, FLOAT

### Result Columns:

Returns SET OF ``(edge_id, color_id)``

Column | Type | Description
---------- | ------- | --------------
**edge_id** | ``BIGINT`` | Identifier of the edge.
**color_id** | ``BIGINT`` | Identifier of the color of the edge. - The minimum value of color is 1.
