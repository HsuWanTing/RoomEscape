#include <string>
using namespace std;

class Player {
public:
	Player();
	Player(int, const char*);
	Player(int, string&);

	int get_player_state();	//�d�ݥثestate	
	int get_player_position();	//�d�ݥثe�b���@�B
	string& get_player_name();	//�d�ݪ��a�W�r
	string& get_player_sex();	//�d�ݪ��a�ʧO

	void set_player_name(const char*);		//��J���a�W�r
	void set_player_name(string&);			//��J���a�W�r
	void set_player_sex(string&);	//���a�� "boy" or "girl"
	void player_position();
	void player_state();

private:
	string _name; // �W�r
	int _sex;	//0�O�k�� 1�O�k��
	int _state;
	int _position;
};