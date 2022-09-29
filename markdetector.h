#ifndef MARKDETECTOR
#define MARKDETECTOR
#include <opencv2/core/core.hpp>
#include <vector>
#include <map>

struct Marker
{
//	cv::Point2f pt[4];
	std::vector<cv::Point2f>pt;
	int id;
	std::vector<cv::Point> contour;
	std::string name;

	//Marker & operator=(const Marker& m) {
	//	for (int i = 0; i < m.pt.size(); ++i)
	//		pt[i] = m.pt[i];
	//	id = m.id;
	//	contour = m.contour;
	//	name = m.name;
	//	return *this;
	//};

	friend bool operator<(const Marker& M1, const Marker& M2)
	{
		return M1.id < M2.id;
	}
	Marker() {
		pt.resize(4);
	}

};

//struct MarkerCandidate
//{
//	cv::Point2f pt[4];
//	int id;
//	std::vector<cv::Point> contour;
//};

#define MarkerCandidate Marker

struct MarkerType
{
	std::map<uint64_t, uint16_t> code_id;
	int nbits;
	int type;
	std::string name;
};

enum DICT_TYPES :uint64_t {
	ALL_DICTS = 0,
	ARUCO_MIP_36h12 = 1,  //*** recommended
	ARUCO = 2,  // original aruco dictionary. By default
	ARUCO_MIP_25h7 = 3,
	ARUCO_MIP_16h3 = 4,
	ARTAG = 5,            //
	ARTOOLKITPLUS = 6,
	ARTOOLKITPLUSBCH = 7,  //
	TAG16h5 = 8,
	TAG25h7 = 9,
	TAG25h9 = 10,
	TAG36h11 = 11,
	TAG36h10 = 12,   // april tags
	CHILITAGS = 13,  // chili tags dictionary . NOT RECOMMENDED. It has distance 0. Markers 806 and 682 should not be

	CUSTOM = 14, // for used defined dictionaries  (using loadFromfile).
};

class  MarkerDetector {
public:
	MarkerDetector();
	void detect(const cv::Mat& input, std::vector<Marker>& detectedMarkers);
	std::vector<MarkerCandidate> prefilterCandidates(std::vector<MarkerCandidate> &MarkerCanditates, cv::Size imgSize);
	bool detectMark(const cv::Mat& in, int& marker_id, int& nRotations, std::string &additionalInfo);
	bool setMarkType(int type);
private:
	int thisImageMinSize_;
	float tooNearDistance_;
	int borderDistThresX_;
	int borderDistThresY_;
	int markerWarpSize_;

//	vector<MarkerType> markCodeId_;
	MarkerType markCodeId_;
	int typeNumber;
};

#endif
