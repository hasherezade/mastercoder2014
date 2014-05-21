#ifndef ATM_RESOURCE_INFO_SERVICE_H
#define ATM_RESOURCE_INFO_SERVICE_H

#include "../values/banknote_bundle.h"

#include <iostream>     // std::cout

class AtmResourceInfoService
{
public:

  AtmResourceInfoService() {}
  virtual ~AtmResourceInfoService() {}

  /**
  * Returns an information about a bundle of banknotes.
  * @return
  */
  virtual BanknoteBundle *getAtmResoures() = 0;
};

#endif // ATM_RESOURCE_INFO_SERVICE_H

