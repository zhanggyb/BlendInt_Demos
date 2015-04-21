/*
 * MBARViewport.hpp
 *
 *  Created on: 2014年12月30日
 *      Author: zhanggyb
 */

#ifndef _MARKERBASEDAR_MBARVIEWPORT_HPP_
#define _MARKERBASEDAR_MBARVIEWPORT_HPP_

#include <blendint/gui/cv-image-view.hpp>

class MBARView: public BlendInt::CVImageView
{
public:

	MBARView();

	virtual ~MBARView();

protected:

	virtual void ProcessImage (cv::Mat& image);

};

#endif /* _MARKERBASEDAR_MBARVIEWPORT_HPP_ */
