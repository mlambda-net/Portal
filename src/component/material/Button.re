[@bs.module "@material-ui/core/Button"] [@react.component]
external make:
  (
    ~label: string=?,
    ~variant: string=?,
    ~disabled: bool=?,
    ~disableElevation: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~centerRipple: bool=?,
    ~href: string=?,
    ~size: string=?,
    ~color: string=?,
    ~fullWidth: bool=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~children: React.element=?,
    ~endIcon: React.element=?,
    unit
  ) =>
  React.element =
  "default";
