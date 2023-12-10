
// 拓扑排序，对整个图（不支持部分）
template<class T>
void arrayWDigraph<T>::_topologicalSorting() {
    int* in_degree = new int[n_vertex + 1]; // 记录每点入度
    int* result = new int[n_vertex + 1]; // 存储排序结果
    int j = 0;
    int k = 0;
    vis = new int[n_vertex + 1];
    fill(vis, vis + n_vertex + 1, 0);
    stack<int> zero_in_degree_nodes; // 记录没有入度（前驱）的点
    
    for (int i = 1; i <= n_vertex; i++){
        in_degree[i] = V[i].in_degree;
        if (V[i].in_degree == 0){
            zero_in_degree_nodes.push(i); // 记录入度=0的点的*V索引（注意转换）*
            vis[i] = 1; // 标记入度=0的点（标记等效于去除点）
        }
    }
    // 处理每个“终点”
    while (!zero_in_degree_nodes.empty()){
        j = zero_in_degree_nodes.top(); zero_in_degree_nodes.pop();
        result[k++] = V[j].node_id; // 对于每个起始点，加上它所有的出边（将其入队）// 有bfs的感觉了！！！
        for (int i = 0; i < G[j].conn_vertices.size(); i++){
            in_degree[getIndex(G[j].conn_vertices[i].node_id)]--; // 等效于去除边，供后续下一个循环判断（判断去掉这些处理完的点和边之后是否满足要求）
        }
        for (int i = 1; i <= n_vertex; i++){
            if (vis[i] == 0 && in_degree[i] == 0) {
                zero_in_degree_nodes.push(i); // 满足，入队列
                vis[i] = 1;
            }
        } // 结束循环后处理下一个始点
    }

    // 非DAG，永远都存在出度不为0的点，即存在环路（或者图不连通），无法拓扑排序
    for (int i = 1; i <= n_vertex; i++){
        if (vis[i] == 0){
            cout << "Cannot get topo rank! " << endl;
            return;
        }
    }

    // 存在拓扑排序，输出（result已排好）
    cout << "Topo rank: ";
    for (int i = 0; i < n_vertex - 1; i++) { // result索引从0开始
        cout << V[getIndex(result[i])].name << "->";
    }
    cout << V[getIndex(result[n_vertex - 1])].name << endl;
}

// 拓扑排序 前端方法
template<class T>
void arrayWDigraph<T>::topoRank() {
    system("cls");
    // 没点
    if (n_vertex == 0){
        cout << "Error: Empty graph!" << endl;
        system("pause");
        return;
    }
    cout << "=======Topo Rank=======" << endl;
    cout << "Result: " << endl;
    // 没边
    if (n_edge == 0){
        for (int i = 1; i < V.size(); i++){
            cout << V[i].node_id << " ";
        }
        cout << endl;
        cout << "Enter to return home" << endl;
        system("pause");
        return;
    }
    // 好使，调用算法
    _topologicalSorting();
    cout << endl;

    system("pause");
}