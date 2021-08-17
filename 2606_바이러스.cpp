#include <iostream>
#include <queue>
using namespace std;

bool visit[101];	// True�̸� �湮�� ��ǻ��, False�̸� ���� �湮���� ���� ��ǻ��
int map[101][101];	// ��ǻ�� ������ ����

int main() {
	int n, networks;
	cin >> n >> networks;

	for (int i = 0; i < networks; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	queue<int> q;
	q.push(1);
	visit[1] = true;
	int cnt = 0;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		// ���̷����� ���� ������ ��ǻ�Ϳ� ����� ��ǻ�� Ȯ��
		for (int i = 1; i <= n; i++) {
			// ���� �湮���� ���� ��ǻ��
			if (map[tmp][i] == 1 && !visit[i]) {
				visit[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	cout << cnt;
}