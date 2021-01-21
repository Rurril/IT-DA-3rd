import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class PuyoPuyo {
	static class graph {
		int x;
		int y;
		
		graph(int a, int b){
			x = a;
			y = b;
		}
		
	}
	
	static ArrayList<graph> puyo_list = new ArrayList<>(); 
	static int op_X[] = {0,0,-1,1};
	static int op_Y[] = {-1,1,0,0};
	static char Map[][] = new char[12][6];
	static int Visited[][] = new int[12][6];
	static boolean chain;
	static int count;
	static int chain_sum = 0;
	
	public static void main(String[] args) throws IOException {
		// bfs
		// 아래 왼쪽부터 0,0으로 탐색 ㄱ
		String s;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i = 11; i >= 0; i--) {
			s = br.readLine();
			for(int j = 0; j < 6; j++) {
				Map[i][j] = s.charAt(j);
			}
		}
		
		while(true) {
			chain = false;
			for(int i = 0; i < 12; i++) {
				for(int j = 0; j < 6; j++) {
					if(Map[i][j] != '.') {
						if(Visited[i][j] == 0)
							bfs(i, j);
					}
					
					if(puyo_list.size() >= 4) {
						chain = true;
						for(int k = 0; k < puyo_list.size(); k++) {
							Map[puyo_list.get(k).x][puyo_list.get(k).y] = '.';
						}
					}
					puyo_list.clear();
				}
			}
			if(!chain)//체인이 탐색동안 없으면
				break;
			else {
				++chain_sum;
				Visited = new int[12][6];
				move();
			}
		}
		
		System.out.println(chain_sum);
		
	}
	
	static void bfs(int x, int y) {
		ArrayList<graph> list = new ArrayList<>();
		int next_x, next_y;
		int temp_x, temp_y;
		
		Visited[x][y] = 1;
		list.add(new graph(x, y));
		puyo_list.add(new graph(x, y));
		while(!list.isEmpty()) {
			temp_x = list.get(0).x;
			temp_y = list.get(0).y;
			for (int i = 0; i < 4; i++) {
				next_x = op_X[i] + temp_x;
				next_y = op_Y[i] + temp_y;
				
				if(next_x >= 0 && next_x < 12 && next_y >= 0 && next_y < 6) {
					if(Map[next_x][next_y] == Map[x][y] && Visited[next_x][next_y] == 0) {
						Visited[next_x][next_y] = 1;
						puyo_list.add(new graph(next_x, next_y));
						list.add(new graph(next_x, next_y));
					}
				}
			}
			list.remove(0);
		}
	}
	
	static void move() {
		for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 12; j++) {
                if (Map[j][i] == '.') {
                    for (int k = j + 1; k < 12; k++) {
                        if (Map[k][i] != '.') {
                            Map[j][i] = Map[k][i];
                            Map[k][i] = '.';
                            break;
                        }
                    }
                }
            }
        }
	}

}

/*

static void move() {
		boolean sw = false;
		for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 12; j++) {
                if (Map[j][i] == '.') {
                    for (int k = j + 1; k < 12; k++) {
                        if (Map[k][i] != '.') {
                            Map[j][i] = Map[k][i];
                            Map[k][i] = '.';
                            sw = false;
                            break;
                        }
                        else {
                        	sw = true;
                        }
                    }
                }
                if(sw)
                	break;//더이상 윗줄에 뿌요없으면 비교 x
            }
        }
	}

*/
