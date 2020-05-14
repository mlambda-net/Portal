[@react.component]
let make = () => {
  <div>
    <Button> {"hello" |> React.string} </Button>
    <div className=Layout.card> {"Sois un pelotudo" |> React.string} </div>
  </div>;
};
