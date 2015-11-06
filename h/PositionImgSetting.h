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
	void set_number(int);
	int get_number();	//�d�ݦ�m�s��	
	Mat get_image(int);	//Ū�ɬd�ݽs��n����
	
	void StitchScreen(int, int, int);	//��J�Ʀrn�A�����Ϥ��s��(n,n+1,n+2,n+12,n+13,n+14,n+24,n+25,n+26)�A�ÿ�X�s�bimage/position_number/stitch_n.jpg
	void StitchScreenAll(int);	//��360�istitch9�������X�ӡA�ÿ�X�s�bimage/position_number/stitch_1.jpg~stitch_36.jpg
	
	//stitch���i�H�����ե�
	void draw_2img_matches(Mat, Mat, int);
	//���զbPositionSetting���n�Aposition���F�����O�O����@���uŪ�@�i��
	Mat GetStitchScreen(int);	//Ū��image/position_number/n.jpg
	//Mat get_screen(int, int);	//��J�����Ϋ������סA�o���������
	void show_screen();		//�q�X��������A�]�A�즲�\��

private:
	string _room_name;
	int _number; // ��m�s��

	Mat stitch2(Mat, Mat, int, int, vector<int> &);
	int getImgAmount(string);
	void Initial3Img(int, int, int);	//stitch_part �N��W�� ���� �ΤU��
	void StitchPart(int, int, int, int, vector<int> &, Mat&);
	
	void draw_matches(Mat, Mat, vector< KeyPoint >, vector< KeyPoint >, vector< DMatch >, int);
	void symmetryTest(const vector<DMatch>, const vector<DMatch>, vector<DMatch>&);
	vector< DMatch > get_good_dist_matches( vector< DMatch >, int);
	vector< DMatch > get_correct_range_matches(vector<DMatch>, Image, Image, int);
	vector< DMatch > get_correct_range_matches_vertical(vector<DMatch>, Image, Image, int);
	
	void get_homography_matrix(Image, Image, vector< DMatch >, Mat&);
	Mat get_blending_matrix(Mat, Mat, Mat);
	Mat get_stitch_matrix(Mat, Mat, int, Mat, vector<int> &);
	//Mat make_screen(int, int, int);	//��J�s�����h�֪�stitch9���ϡA�H�Τ�����X�סA������X��
};

#endif