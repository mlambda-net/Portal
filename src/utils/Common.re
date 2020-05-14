let get_default = (v: option('a), default: 'a): 'a => {
  switch (v) {
  | Some(k) => k
  | None => default
  };
};

let get_bool = (v: option(bool)): bool => get_default(v, false);
let get_string = (v: option(string)): string => get_default(v, "");

let get_int = (v: option(int)): int => get_default(v, 0);
let get_float = (v: option(float)): float => get_default(v, 0.0);
let get_element = (v: option(React.element)): React.element =>
  get_default(v, React.string(""));
let get_click =
    (v: option(ReactEvent.Mouse.t => unit)): (ReactEvent.Mouse.t => unit) =>
  get_default(v, _ => ());
