# coding: utf-8
import unittest

import osaka


class OsakaTest(unittest.TestCase):
    def test_ookini(self):
        self.assertEqual(
            osaka.translate("ありがとう"),
            "おおきに")

    def test_ookiniomasu(self):
        self.assertEqual(
            osaka.translate("ありがとうございます"),
            "おおきにおます")

    def test_honmayaroka(self):
        self.assertEqual(
            osaka.translate("ほんとうですか？"),
            "ホンマやろか？")


if __name__ == '__main__':
    unittest.main()
