open BsStorybook;

module Settings = {
  type sizeOption = {
    small: string,
    medium: string,
    large: string,
  };

  let sizeOptions: Knobs.selectConfig(sizeOption) = {
    small: "small",
    medium: "medium",
    large: "large",
  };

  type colorOption = {
    default: string,
    inherit_: string,
    primary: string,
    secondary: string,
  };

  let colorOptions: Knobs.selectConfig(colorOption) = {
    default: "default",
    inherit_: "inherit",
    primary: "primary",
    secondary: "secondary",
  };

  type variantOption = {
    text: string,
    outlined: string,
    contained: string,
  };

  let variantOptions: Knobs.selectConfig(variantOption) = {
    text: "text",
    outlined: "outlined",
    contained: "contained",
  };
};

let useStyles =
  Styles.makeStyle((the: Styles.theme) => {
    Js.log(the.direction);
    Styles.createStyles({
      "body": {
        "background": "blue",
        "& > *": {
          "margin": "100000",
        },
      },
    });
  });

Story.storiesOf("Button Component", [%bs.raw "module"])
->Story.addDecorator(Knobs.withKnobs)
->Story.add("Button", () => {
    let x = useStyles();

    <div className={Js.Dict.get(x, "body") |> Common.get_string}>
      <Button
        label={Knobs.text(~label="label", ~defaultValue="Button", ())}
        disabled={Knobs.boolean(~label="disabled", ~defaultValue=false, ())}
        fullWidth={Knobs.boolean(
          ~label="full width",
          ~defaultValue=false,
          (),
        )}
        disableElevation={Knobs.boolean(
          ~label="disable elevation",
          ~defaultValue=false,
          (),
        )}
        centerRipple={Knobs.boolean(
          ~label="center  ripple",
          ~defaultValue=false,
          (),
        )}
        disableRipple={Knobs.boolean(
          ~label="disable  ripple",
          ~defaultValue=false,
          (),
        )}
        disableFocusRipple={Knobs.boolean(
          ~label="disable focus ripple",
          ~defaultValue=false,
          (),
        )}
        size={Knobs.select(
          ~label="size",
          ~options=Settings.sizeOptions,
          ~defaultValue=Settings.sizeOptions.small,
          (),
        )}
        color={Knobs.select(
          ~label="color",
          ~options=Settings.colorOptions,
          ~defaultValue=Settings.colorOptions.default,
          (),
        )}
        variant={Knobs.select(
          ~label="variant",
          ~options=Settings.variantOptions,
          ~defaultValue=Settings.variantOptions.text,
          (),
        )}
        endIcon={"..." |> React.string}
        onClick={Action.action("I Clicked The Button!")}>
        {"Hi" |> React.string}
      </Button>
    </div>;
  })
->Story.add("Button as link", () => {
    <Button
      href={Knobs.text(~label="href", ~defaultValue="http://google.com", ())}>
      {"Link" |> React.string}
    </Button>
  });
