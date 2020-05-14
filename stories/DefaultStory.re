open BsStorybook;

Story.storiesOf("Layout Story", [%bs.raw "module"])
->Story.addDecorator(Knobs.withKnobs)
->Story.add("Layout", () => {<Default />});