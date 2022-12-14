#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void put_string(Mat &frame, string text, Point pt, int value)
{
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);
}

int main()
{
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		cout << "Camera didn't connected. " << endl;
		exit(1);
	}

	cout << "Width " << capture.get(CAP_PROP_FRAME_WIDTH)<< endl;
	cout << "Height" << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "Exposure" << capture.get(CAP_PROP_EXPOSURE) << endl;
	cout << "Brighness" << capture.get(CAP_PROP_BRIGHTNESS) << endl;

	for(;;) {
		Mat frame;
		capture.read(frame);

		put_string(frame, "EXPOS: ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE));
		imshow("view Camera" , frame);
		if(waitKey(30) >= 0) break;
	}
	return 0;
}
