cmake_minimum_required(VERSION 2.8)
project (zad8)

set ( tests_hdrs
	tests/assert_exception.h
	tests/test_case.h
	tests/tests.h
)

set (api_hdrs
	api/atm_resource_info_service.h
	api/atm_withdrawal_calculation_service.h
)

set (values_hdrs
	values/banknote_bundle.h
	values/denomination.h
	values/denomination_bundle.h
	values/money.h
	values/suggested_withdrawal.h
	values/withdrawal_info.h
)

set (values_srcs
	values/withdrawal_info.cpp
)

set (hdrs
	atm_withdrawal_calculation_service_impl.h
	withdrawal_info_impl.h
	atm_resource_info_service_impl.h
	${tests_hdrs}
	${api_hdrs}
	${values_hdrs}
)

set (tests_srcs
	tests/test_case.cpp
	tests/tests.cpp
)

set (srcs
	${tests_srcs}
	${values_srcs}
	atm_withdrawal_calculation_service_impl.cpp
	withdrawal_info_impl.cpp
	atm_resource_info_service_impl.cpp
	main.cpp
)

SOURCE_GROUP("Header Files\\api" FILES ${api_hdrs} )
SOURCE_GROUP("Header Files\\values" FILES ${values_hdrs} )
SOURCE_GROUP("Header Files\\tests" FILES ${tests_hdrs} )

SOURCE_GROUP("Source Files\\values" FILES ${values_srcs} )
SOURCE_GROUP("Source Files\\tests" FILES ${tests_srcs} )

add_executable (zad8 ${hdrs} ${srcs})

