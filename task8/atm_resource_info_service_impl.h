#ifndef ATM_RESOURCE_INFO_SERVICE_IMPL_H
#define ATM_RESOURCE_INFO_SERVICE_IMPL_H

#include "values/banknote_bundle.h"
#include "api/atm_resource_info_service.h"

class AtmResourceInfoServiceImpl : public AtmResourceInfoService
{
public:
	AtmResourceInfoServiceImpl(std::vector<DenominationBundle> dm)
		: bundle(NULL) 
	{
		bundle = new BanknoteBundle(dm);
	}

	virtual ~AtmResourceInfoServiceImpl() { delete bundle; }

	virtual BanknoteBundle *getAtmResoures() { return bundle; }

protected:
	BanknoteBundle* bundle;
};

#endif // ATM_RESOURCE_INFO_SERVICE_IMPL_H

