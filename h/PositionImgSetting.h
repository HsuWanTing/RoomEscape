#ifndef _POSITIONSETTING_H_
#define _POSITIONSETTING_H_
#include "Image.h" 
#include <string>
using namespace std;


class PositionImgSetting {
public:
	PositionImgSetting();
	PositionImgSetting(string&, int);	//��room name �M position�s��

	void set_room_name(int);
	string& get_room_name();	
	void set_position_number(int);
	int get_position_number();	//�d�ݦ�m�s��	
	
	int StitchSceneRange(int, int, int, int);	//stitch from num1 to num2
	void StitchSceneAll(int);	//��360�istitch�ϳ������X��
	
	void draw_2img_matches(Mat, Mat, int);

private:
	string _room_name;
	int _number; // ��m�s��

	void StitchScene(int, int, int);	//��J�Ʀrn�A�����Ϥ��s��n�A�ÿ�X�s�bimage/room name/position_number/stitch/1 or 2/stitch_n.jpg
	Mat stitch2(Mat, Mat, int, int, vector<int> &);
	int getImgAmount(string);
	void Initial3Img(int, int, int);	//stitch_part �N��W�� ���� �ΤU��
	void StitchPart(int, int, int, int, vector<int> &, Mat&);
	
	int img_capture(Mat, int, int, int, int, Image&);
	void draw_matches(Mat, Mat, vector< KeyPoint >, vector< KeyPoint >, vector< DMatch >, int);
	void symmetryTest(const vector<DMatch>, const vector<DMatch>, vector<DMatch>&);
	vector< DMatch > get_good_dist_matches( vector< DMatch >, int);
	//vector< DMatch > get_correct_range_matches(vector<DMatch>, Image, Image, int);
	
	void get_homography_matrix(Image, Image, vector< DMatch >, Mat&);
	Mat get_blending_matrix(Mat, Mat, Mat);
	Mat get_stitch_matrix(Mat, Mat, int, Mat, vector<int> &);
};

#endif