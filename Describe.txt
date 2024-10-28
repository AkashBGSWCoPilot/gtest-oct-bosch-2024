Describe(string_calculator_add) {
  Describe(when_passed_a_single_number) {
		It (returns_0_for_empty_string) {
			Assert::That(calculator.Add(""), Equals(0));
		}
 
		It (returns_0_for_zero) {
			Assert::That(calculator.Add("0"), Equals(0));
		}
		StringCalculator calculator;
	};
};
