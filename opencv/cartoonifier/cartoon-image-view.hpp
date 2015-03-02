/*
 * cartoon-image-view.hpp
 *
 *  Created on: 2015年3月2日
 *      Author: zhanggyb
 */

#ifndef _CARTOONIFIER_CARTOON_IMAGE_VIEW_HPP_
#define _CARTOONIFIER_CARTOON_IMAGE_VIEW_HPP_

#include <gui/cv-image-view.hpp>

namespace BI = BlendInt;

class CartoonImageView: public BI::CVImageView
{
public:

	CartoonImageView();

	virtual ~CartoonImageView();

protected:

	virtual void ProcessImage (cv::Mat& image);

private:

	//void MedianBlur (const cv::Mat& gray, cv::Mat& edges, int blue_size);



};

#endif /* _CARTOONIFIER_CARTOON_IMAGE_VIEW_HPP_ */
