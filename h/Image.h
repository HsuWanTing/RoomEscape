#include <string>
#include <opencv2/contrib/contrib.hpp> 

using namespace std;
using namespace cv;

class Image {		//�@�i�Ϫ���T
public:
	Image();
	Image(string&);	//Ū�����|�ð�SIFT
	Image(Mat);	//��J�x�}�ð�SIFT

	Mat mat();	//��Ximg��Mat	
	vector < KeyPoint > keypoints();
	Mat descriptors();
	//int get_image_number();

	void set_image(string&);	//Ū�����|�ð�SIFT�A��Xkeypoints�Mdescriptors
	void set_image(Mat);	//��J�x�}�ð�SIFT�A��Xkeypoints�Mdescriptors

	void set_keypoints(string&);	//Ū�����|�ð�SIFT�A��Xkeypoints�Ӥw
	void set_keypoints(Mat);	//��J�x�}�ð�SIFT�A��Xkeypoints�Ӥw
	void set_keypoints(vector < KeyPoint >);	//���wkeypoints

	//void set_descriptors(vector < KeyPoint >);	//�Ϋ��wkeypoints���descriptors

private:
	Mat _img;
	vector < KeyPoint > _keypoints;
	Mat _descriptors;
	//int _number;	//�Ϥ��s���A��K����bposition���ɭԹ�Ϥ����ǰ��޲z
};