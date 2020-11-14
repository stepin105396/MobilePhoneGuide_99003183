#include "unity.h"
#include "my_project.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
void test_admin()
{
    TEST_ASSERT_EQUAL(1,admin("akshaysai","akshay"));
}

void test_list(void)
{
  TEST_ASSERT_EQUAL(5, showdeviceno("Samsung"));
}

void test_deviceprocessor(void)
{
  TEST_ASSERT_EQUAL_STRING("5Pro",a_mobiledetails(712));
}
void test_device_battery(void)
{
    TEST_ASSERT_EQUAL(1, devicebattery(5000));
}

int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();
/* Run Test functions */
    RUN_TEST(test_admin);
    RUN_TEST(test_list);
    RUN_TEST(test_deviceprocessor);
    RUN_TEST(test_device_battery);


  /* Close the Unity Test Framework */
  return UNITY_END();
}
