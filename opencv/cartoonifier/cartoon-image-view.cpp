/*
 * cartoon-image-view.cpp
 *
 *  Created on: 2015年3月2日
 *      Author: zhanggyb
 */

#include <opencv2/imgproc/imgproc.hpp>

#include "cartoon-image-view.hpp"

CartoonImageView::CartoonImageView()
: CVImageView()
{

}

CartoonImageView::~CartoonImageView ()
{
}

void CartoonImageView::ProcessImage (cv::Mat& image)
{
	cv::Mat gray, edges, masks;

	cv::cvtColor(image, gray, CV_RGB2GRAY);

	cv::medianBlur(gray, gray, 7);
	cv::Laplacian(gray, edges, CV_8U, 5);
	cv::threshold(edges, masks, 80, 255, cv::THRESH_BINARY_INV);

	image = masks;
}
