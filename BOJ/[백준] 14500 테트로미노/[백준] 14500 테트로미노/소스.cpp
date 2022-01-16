// [��ó] ��Ʈ�ι̳�(���� 14500)|�ۼ��� biotite135 https://blog.naver.com/biotite135/222529960961

#include<iostream>
#include<vector>
#include<algorithm>

int M, N;
int map[501][501];
int ans = 0;

//��� �ʱ�ȭ
std::vector<std::vector<std::vector<int>>> block = {
    {{1,1,1,1}},
    {{1,1},{1,1}},
    {{1,0},{1,0},{1,1}},
    {{1,0},{1,1},{0,1}},
    {{1,1,1},{0,1,0}}
};

//ȸ��
void rotate(int type){
    int r = block[type].size();
    int c = block[type][0].size();
    std::vector<std::vector<int>> tmp(c, std::vector<int>(r));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            tmp[j][r - i - 1] = block[type][i][j];
        }
    }

    block[type] = tmp;

}

//������
void flip(int type){
    int r = block[type].size();
    int c = block[type][0].size();

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c / 2; j++) {
            int tmp = block[type][i][c - j - 1];
            block[type][i][c - j - 1] = block[type][i][j];
            block[type][i][j] = tmp;
        }
    }
}

//��ƼĿ ���̱�
int checkSticker(int type, int y, int x){
    int r = block[type].size();
    int c = block[type][0].size();

    if (x + c > M || r + y > N)return 0;

    int count = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (block[type][i][j] != 0) {
                count += map[i + y][j + x];
            }
        }
    }

    return count;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }


    //����� ���� ����
    for (int k = 0; k < 5; k++){
        for (int rot = 0; rot < 4; rot++) {//��� ȸ��
            for (int f = 0; f < 4; f++) {//��� ��Ī
                //����� ��ġ
                for (int i = 0; i < N; i++)                {
                    for (int j = 0; j < M; j++)
                        ans = std::max(checkSticker(k, i, j), ans);
                    
                }
                flip(k);
            }
            rotate(k);
        }
    }

    std::cout << ans;
}
