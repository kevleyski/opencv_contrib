// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#include "perf_precomp.hpp"
#include "opencv2/cann_interface.hpp"
using namespace perf;

class CannEnvironment : public ::testing::Environment
{
public:
    virtual ~CannEnvironment() = default;
    virtual void SetUp() CV_OVERRIDE
    {
        initAcl();
        cv::cann::setDevice(DEVICE_ID);
        initDvpp();
    }
    virtual void TearDown() CV_OVERRIDE
    {
        finalizeAcl();
        cv::cann::resetDevice();
        finalizeDvpp();
    }
};

static void initTests()
{
    CannEnvironment* cannEnv = new CannEnvironment();
    ::testing::AddGlobalTestEnvironment(cannEnv);
}

CV_PERF_TEST_MAIN("cannops", initTests())
