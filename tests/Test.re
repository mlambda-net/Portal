open Jest;
open Expect;

describe("Some test", () => {
  test("sum", () => {
    expect(1 + 2) |> toBe(3)
  })
});