using System;
using System.Collections.Generic;
using System.Text;

namespace AdventOfCode.ProjectHelper
{
	public class Result
	{
		public bool Success { get; }
		public string ErrorMessage { get; }

		private Result(bool success)
		{
			Success = success;
			ErrorMessage = string.Empty;
		}

		private Result(bool success, string msg)
		{
			Success = success;
			ErrorMessage = msg;
		}

		public static Result OK()
		{
			return new Result(true);
		}

		public static Result Error(string msg)
		{
			return new Result(false, msg);
		}
	}
}
