# fc-path

Get the fully-qualified path to a fontconfig match

## Building & Usage

### Building

#### Dependencies
- meson
- fontconfig

#### Build
`meson build && ninja -C build`

The executable will be built to `build/fc-path`.

### Usage

#### Dependencies
- fontconfig

#### Use

`build/fc-path mono`
```
/usr/share/fonts/noto/NotoMono-Regular.ttf
```

## License

This work, written by Robin Broda (coderobe) in 2018, is licensed under the terms of the GNU Affero General Public License v3.0
