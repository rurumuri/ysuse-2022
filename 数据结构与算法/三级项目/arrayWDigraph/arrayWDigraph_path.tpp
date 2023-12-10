
//// 以下为基于Floyd算法寻路的实现

// Floyd 打印最短路径子方法，递归遍历
template<class T>
void arrayWDigraph<T>::_floyd_PrintPath(int i, int j) {
    int k = path_floyd[i][j];
    if (k == -1) return; // 说明没有中转顶点，直接返回.
    _floyd_PrintPath(i, k); // 寻找i和k之间
    cout << V[k].node_id << "->";
    _floyd_PrintPath(k, j); // 寻找k和j之间
}

// Floyd 打印最短路径方法
template<class T>
void arrayWDigraph<T>::_floydPrintPath() {
    int i, j;
    for (i = 1; i < n_vertex + 1; i++) {
        for (j = 1; j < n_vertex + 1; j++) {
            if (dis_floyd[i][j] == INF) {
                // 无法到达设置距离为无穷大，则他们之前没有路径
                cout << V[i].node_id << " and " << V[j].node_id << " is not connectedSets!" << endl;
            }
            else {
                cout << V[i].node_id << " and " << V[j].node_id << "\'s shortest path length is" << dis_floyd[i][j] << endl;
                cout << "Path: " << V[i].node_id << "->";
                _floyd_PrintPath(i, j);
                cout << V[j].node_id << endl;
            }
        }
    }
}

// Floyd 算法求所有点到其他点的最短路径，此为后端核心算法
template<class T>
void arrayWDigraph<T>::_floyd() {
    // init
    dis_floyd = new T * [n_vertex + 1];
    for (int i = 0; i < n_vertex + 1; i++){
        dis_floyd[i] = new T[n_vertex + 1];
    }
    path_floyd = new int* [n_vertex + 1];
    for (int i = 0; i < n_vertex + 1; i++){
        path_floyd[i] = new int[n_vertex + 1];
        for (int j = 0; j < n_vertex + 1; j++){
            path_floyd[i][j] = -1;
        }
    }
    for (int i = 0; i < n_vertex + 1; i++) {
        for (int j = 0; j < n_vertex + 1; j++) {
            if (i == j) dis_floyd[i][j] = 0;
            else dis_floyd[i][j] = INF;
        }
    }
    for (int i = 1; i < G.size(); i++){ // 将直接连接两个端点的边的权映射到dis中
        for (int j = 0; j < G[i].conn_vertices.size(); j++){
            dis_floyd[i][getIndex(G[i].conn_vertices[j].node_id)] = G[i].conn_vertices[j].node_weight;
        }
    }

    // 计算部分
    for (int k = 1; k < n_vertex + 1; k++) {
        //不断插点
        for (int i = 1; i < n_vertex + 1; i++) {
            for (int j = 1; j < n_vertex + 1; j++) {
                //对图中所有点之间的最短距离进行更新。
                if (dis_floyd[i][j] > dis_floyd[i][k] + dis_floyd[k][j]) {
                    path_floyd[i][j] = k; // 记录中转顶点，供后续输出路径（原理概述：比如ij用k，ik直接用l...直接递归寻找并输出iljk即可）
                    dis_floyd[i][j] = dis_floyd[i][k] + dis_floyd[k][j];//更新。
                }
            }
        }
    }
}

// Floyd 算法求所有点到其他点的最短路径，此为前端函数，检查和提示作用
template<class T>
void arrayWDigraph<T>::floydGetPath() {
    system("cls");
    if (n_vertex == 0){
        cout << "Error: Graph empty" << endl;
        system("pause");
        return;
    }
    cout << "=======All Shortest Path=======" << endl;
    cout << "Result: ";
    _floyd();
    _floydPrintPath();
    cout << "===============================" << endl;
    system("pause");
}


//// 以下为基于Dijkstra算法寻路的实现

// Dijkstra算法核心部分，计算了起始点到所有其他点的最短路径（单源）并保存到dis_dijkstra数组中
// 接受参数为点索引
template<class T>
void arrayWDigraph<T>::_dijkstra(int start){
    for (int i = 1; i <= n_vertex - 1; i++) { // 用n-1个点松弛，更新n-1次dis_dijkstra数组

        // 寻找距离最近的点及其min距离的“确定值”
        T min = INF;
        int min_node_id = 0;
        for (int j = 1; j <= n_vertex; j++) { // j是下标
            // 寻找当前非自己的最近点作为“跳板”（中转点），后续以此点出发，松弛其它距离
            if (dis_dijkstra[j] < min && vis[j] == 0) {
                min = dis_dijkstra[j];
                min_node_id = V[j].node_id; // 中转点的编号
            }
        }

        // 没有可用于松弛的点
        if (min_node_id == 0){
            continue;
        }

        // 可以更新
        vis[getIndex(min_node_id)] = 1; // 已找到到达minnode的最短路径（确定值），标记vis为1
        auto pointer = iterator(min_node_id);
        int next, pos;
        T weight;
        // 寻找目前用于松弛的点的出边中 且除了已经寻得“确定值”的点后的点 尝试进行松弛
        while ((next = pointer->next(weight, pos)) != 0) {
            if (vis[getIndex(next)] == 0 && dis_dijkstra[getIndex(next)] > G[getIndex(min_node_id)].conn_vertices[pos].node_weight + dis_dijkstra[getIndex(min_node_id)]) {
                dis_dijkstra[getIndex(next)] = G[getIndex(min_node_id)].conn_vertices[pos].node_weight + dis_dijkstra[getIndex(min_node_id)];
                path_dijkstra[getIndex(next)] = getIndex(min_node_id); // 更新此点的前置点为此时的松弛点的编号
            }
        }
    }
}


// 计算多源最短路径的算法，接受参数为点索引，返回单源多点最短路径dis_dijkstra数组
// 此为算法中间层，初始化必要数据，异常捕获，预处理路径细节数据等
template<class T>
T* arrayWDigraph<T>::_shortPathDijkstra(int start, int end){

    // 初始化过程必要的数组
    dis_dijkstra = new T[n_vertex + 1];
    fill(dis_dijkstra, dis_dijkstra + n_vertex + 1, INF);
    dis_dijkstra[0] = n_vertex;
    dis_dijkstra[start] = 0; // 自己到自己为0

    path_dijkstra = new int[n_vertex + 1]; // 供保存路径
    path_dijkstra[start] = start;

    vis = new int[n_vertex + 1];
    fill(vis, vis + n_vertex + 1, 0);
    vis[start] = 1;

    // 使用迭代器遍历起始点的所有边，初始化dis_dijkstra和path_dijkstra
    auto cur_node = iterator(V[start].node_id);
    int next_node_id;
    T weight;
    while ((next_node_id = cur_node->next(weight)) != 0) {
        dis_dijkstra[getIndex(next_node_id)] = weight;
        path_dijkstra[getIndex(next_node_id)] = start; // 初始化每个点的上一个点为start
    }

    // 核心dijkstra算法处理
    _dijkstra(start);

    // 根据dijkstra结果的dis_dijkstra数组，记录各点可到达情况
    is_reachable = new bool[n_vertex + 1];
    for (int i = 1; i <= n_vertex; i++){
        is_reachable[i] = true;
        if (dis_dijkstra[i] == INF){
            is_reachable[i] = false;
        }
    }
    // 如果不能到达，寻路失败，返回NULL，由前端函数处理并输出
    if (!is_reachable[end]){
        return NULL;
    }


    while(!path_stack_dijkstra.empty()) path_stack_dijkstra.pop(); // 清空栈
    int path_node_num_cnt = 0;

    // 回溯压栈（便于正向输出），并计算cnt路径经过的节点个数
    // 注意此时end start 为索引，注意后续输出时转换
    while (end != start) {
        path_stack_dijkstra.push(end);
        path_node_num_cnt++;
        end = path_dijkstra[end]; // 逆序回溯
    }
    dis_dijkstra[0] = path_node_num_cnt; // 活用首元素保存路径节点数

    is_reachable = NULL;
    return dis_dijkstra;
}


// 使用Dijkstra算法 获取单源最短路径。此为Dijkstra算法的结果处理和回溯输出最短路径
// Dijkstra算法计算起始点到所有其他点的最短路径，此函数仅取目标终点的最短路径并输出
template<class T>
void arrayWDigraph<T>::_dijkstraResult(int start, int end){
    start = getIndex(start); // 转换为索引
    end = getIndex(end);
    T* distance = _shortPathDijkstra(start, end);

    // 处理NULL
    if (!distance) {
        cout << "Not exists path from " << V[start].node_id << " to " << V[end].node_id << endl;
        return;
    }

    T path_node_num = distance[0];

    // 输出最短路径长
    cout << "From " << V[start].node_id << " to " << V[end].node_id << "\'s shortest path length is " << dis_dijkstra[end] << endl;

    // 回溯输出路径
    cout << "Path: " << V[start].node_id << "->";
    for (int i = 1; i <= path_node_num; i++){
        cout << V[path_stack_dijkstra.top()].node_id;
        if (i != path_node_num){cout << "->";}
        path_stack_dijkstra.pop();
    }
    cout << endl;
}

// 使用Dijkstra算法 获取单源最短路径。此为前端函数，实现处理输入和提示等功能
template<class T>
void arrayWDigraph<T>::dijkstraGetPath(){
    system("cls");
    cout << "=======Single Vertex Shortest Path=======" << endl;
    cout << "Enter the start node_id" << endl;
    int node_id_start = 0;
    int node_id_end = 0;

    // check
    while (true) {
        cout<<"> "; cin >> node_id_start;
        if (!existVertex(node_id_start)){
            cout << "Start node not exists! Try again. " << endl;
        }
        else{
            break;
        }
    }
    cout << "Enter the end node_id" << endl;
    while (true) {
        cout<<"> "; cin >> node_id_end;
        if (!existVertex(node_id_end)){
            cout << "End node not exists! Try again. " << endl;
        }
        else{
            break;
        }
    }
    if (node_id_start == node_id_end){
        cout << "Bad route! The start and end is equal!" << endl;
        system("pause");
        return;
    }else{
        _dijkstraResult(node_id_start, node_id_end);
    }
    system("pause");
}