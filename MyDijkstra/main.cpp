#include <iostream> //��׼������� 
#include <queue> // ���п� �����ĳ�Ա priority_queue<T> 
#include <vector> //����vector 
#include <sstream> //����stringstream 
#include <cstring> //����memset() 
#include <string> //����string 
#include <cstdlib> //����malloc 
#include <cassert> //����assert 
#include <cstdio> //����Ǳ�׼�������������C���԰� ����stdin ָ�� 
#include <algorithm>
#include <malloc.h> //����_msize() ����malloc�����˶����ڴ� 
#define INF -1
#define LOCAL
using namespace std;
typedef vector<int> ROW;
typedef struct Edge
{
	int from, to, dist;
	Edge(int _from, int _to, int _dist) :from(_from), to(_to), dist(_dist) {
	}
	friend ostream& operator <<(ostream &out, Edge &edge) {
		out << edge.from << ' ' << edge.to << ' ' << edge.dist;
		return out;
	}
}Edge;
template <typename T>
void travel_vec(vector<T> &vec) {
	for (typename vector<T>::iterator vec_it = vec.begin(); vec_it != vec.end(); vec_it++) {
		cout << *vec_it << "	";
	}
	cout << endl;
}
struct Graph
{
	bool isDirect;//�Ƿ�Ϊ����ͼ 
	int points, edge_count; //points������Ŀ,�߼���
	vector<Edge> edges;//�洢�ߵ�һ����̬���� 
	vector<ROW> graph_index;//������ͼ������edge �洢�ߵ������Ķ�ά���� 
	Graph(int _points, bool _isDirect) :points(_points), isDirect(_isDirect) {//graph�Ĺ��캯�� 
		this->edges.clear();
		this->edge_count = 0;
		this->graph_index.clear();
		for (int i = 0; i<_points; i++) {
			this->graph_index.push_back(ROW());//�ڶ�ά�����м���ÿһ�� ��ÿһ������ʾÿһ���������ӵı� 
		}
	}
	void addEdge(int _from, int _to, int _dist) {
		assert(_from >= 0 && _from<points);
		assert(_to >= 0 && _to<points);
		assert(graph_index[_from].size()<points);
		this->edges.push_back(Edge(_from, _to, _dist));//���������� 
		this->edge_count++;//�߼���++ 
		graph_index[_from].push_back(edges.size() - 1);//�ѱߵ����������ά������ 
		if (!isDirect) {
			graph_index[_to].push_back(edges.size() - 1);//���������ͼ��ѷ����·���ִ����Ӧ������ 
		}

	}
	bool hasEdge(int _from, int _to) {//��ѯ�Ƿ���������� 
		for (int i = 0; i<edges.size(); i++) {
			if (edges[i].from == _from&&edges[i].to == _to) {
				return true;
			}
		}
		return false;
	}
};
struct HeapNode//�ѽڵ�洢Ԫ�� 
{
	int h_dist, h_ver;//Ԫ���а�������Ͷ��� 
	bool operator <(const HeapNode &rhs) const {
		return this->h_dist>rhs.h_dist;// 
	}
	HeapNode(int _hver, int _hdist) :h_dist(_hdist), h_ver(_hver) {
	}
};
struct Dijkstra
{
	bool *marked;//�ҹ���Ԫ�ص����� 
	int *dist;//�洢����Դ�㵽ĳ����ľ��� 
	int *path;//����·��
	Graph &graph;
	Dijkstra(Graph &_graph) :graph(_graph) {
		marked = (bool *)malloc(graph.points * sizeof(bool));//�ж��ٸ���ͷ�����ٸ��ռ����洢�Ƿ��ѯ������� 
		dist = (int *)malloc(graph.points * sizeof(int));//�洢Դ�㵽ĳ����ľ��� 
		path = (int *)malloc(graph.points * sizeof(int));//�洢ĳ����ǰ���ڵ� ���ĸ��ط����� 
	}
	void TravelDist() {//����dist���� 
		cout << "Dist array is ";
		for (int i = 0; i<graph.points; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
	}
	void TravelPath() {//����path���� 
		cout << "Path array is ";
		for (int i = 0; i<graph.points; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
	}
	void dijkstra(int source) {
		priority_queue<HeapNode> qheap;//���ȶ��� ��·���Ƚ϶̵��ȳ����� 
		memset(dist, INF, _msize(dist)); //��ʼ��distȨֵ���� ȫ��Ϊ���ɴ�  
//		for (int i = 0; i < graph.points; i++) dist[i] = INF, marked[i] = false;
		dist[source] = 0;//Դ�㵽�Լ��ľ�����0 	
		memset(marked, false, _msize(marked));
		//memset(marked, false, sizeof(bool)*graph->points);
		path[source] = source;
		qheap.push(HeapNode(source,0));//Դ����� 
		while (!qheap.empty()) {//���в�Ϊ�� ��ִ�г��� 
			HeapNode tempnode = qheap.top();//���ӵ�Ԫ������Դ�㵽ĳ���������С���Ǹ�Ԫ�� 
			qheap.pop();//ɾ����ͷ 
			int tempver = tempnode.h_ver;//�ҵ����ӵĵ� 
			if (marked[tempver]) continue;//���˵������Ѿ������ʹ��ˣ�ȡ��һ����ͷ 
			marked[tempver] = true;//��λ ����㱻���ʹ� 
			int row_size=(this->graph.graph_index[tempver]).size();
			for (int i = 0; i<row_size; i++) {//�ɳڲ��� 
				Edge &tempEdge = graph.edges[this->graph.graph_index[tempver][i]];
				if(tempEdge.to==tempver&&!graph.isDirect) {
					swap(tempEdge.from, tempEdge.to);
				}
				if (dist[tempEdge.to] == INF || dist[tempEdge.to]>dist[tempver] + tempEdge.dist) {
					//���˵Դ�㵽ĳ����洢�ľ��������� ����֮ǰ�洢�ľ������ Դ�㵽��ǰ����ϵ�ǰ�㵽��Ѱ�ҵĵ�ľ���֮�� 
					//V0 �� V4 ֮ǰ�ľ�����20������INF ����dist(v0->v1)+dist(v1->v4)<dist(v0->v4) ���滻dist(v0->v4)
					dist[tempEdge.to] = dist[tempver] + tempEdge.dist;
					path[tempEdge.to] = tempver;//���Ҵ洢Ѱ�ҵĵ��ǰ���ڵ� ����˵��v4��ǰ���ڵ����v1 
					qheap.push(HeapNode(tempEdge.to, dist[tempEdge.to]));//����������� 
				}
			}
		}
	}
	~Dijkstra() {
		delete marked;
		delete dist;
		delete path;
	}
};
int main(int argc, char *argv[]) {
#ifdef LOCAL
	FILE *file = NULL;
	file = freopen("intext.txt", "r", stdin);
	if (file != NULL) {
		cout << "read successfully" << endl;
	}
	//	freopen("outtext.txt","w",stdout);
#endif
	string line;
	while (getline(cin, line)) {//��ȡ�����һ�� 
								//		cout << line << endl;
		int points, edges;//�洢��ͱ� 
		int source_num;
		stringstream ss(line);
		ss >> points;
		ss >> edges;//���ַ���ת��Ϊint 
		Graph graph(points, false);
		for (int e = 0; e<edges+1&&getline(cin, line); e++) {//��������ı� 
			ss.clear();
			ss.str(line);
			int in_num;
			int argu[3];//��ÿһ�еĲ����������� 
			if (e == edges) {
				ss >> source_num;
				break;
			}
			for (int i = 0; i<3 && ss >> in_num; i++) {
				argu[i] = in_num;
			}
			//cout<<argu[0]<<' '<<argu[1]<<' '<<argu[2]<<endl;
			if (!graph.hasEdge(argu[0], argu[1])) {//���˵ͼ���治������һ���� ��ֹƽ�б� 
				graph.addEdge(argu[0], argu[1], argu[2]);//�ͼ������ͼ 
			}
		}
//		cout << source_num << endl;
		//travel_vec(graph.edges);//���� 
		Dijkstra dijkstra(graph);
		dijkstra.dijkstra(source_num);
		dijkstra.TravelDist();
		dijkstra.TravelPath();
	}
	system("pause");
	return 0;
}

