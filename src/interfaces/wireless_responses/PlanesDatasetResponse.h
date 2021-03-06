#ifndef AHRS_PLANESDATASETRESPONSE_H
#define AHRS_PLANESDATASETRESPONSE_H

#include "Response.h"

#include <string>
#include <vector>

namespace communication
{
    class PlanesDatasetResponse final : public Response
    {
    public:
        PlanesDatasetResponse(const std::string& dataset);
        ~PlanesDatasetResponse();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor& visitor) override;

        void setDataset(const std::string& dataset);

        std::string getDataset() const;

    private:
        virtual void initializeDataSize() override;

        std::string dataset_;
    };
}

#endif
